// Gl_template.c
//Wy³šczanie b³êdów przed "fopen"
#define  _CRT_SECURE_NO_WARNINGS

#define _GLIBCXX_USE_NANOSLEEP	//asyncF

// £adowanie bibliotek:

#ifdef _MSC_VER                         // Check if MS Visual C compiler
#  pragma comment(lib, "opengl32.lib")  // Compiler-specific directive to avoid manually configuration
#  pragma comment(lib, "glu32.lib")     // Link libraries
#endif




// Ustalanie trybu tekstowego:
#ifdef _MSC_VER        // Check if MS Visual C compiler
#   ifndef _MBCS
#      define _MBCS    // Uses Multi-byte character set
#   endif
#   ifdef _UNICODE     // Not using Unicode character set
#      undef _UNICODE 
#   endif
#   ifdef UNICODE
#      undef UNICODE 
#   endif
#endif
#include <windows.h>            // Window defines
#include <gl\gl.h>              // OpenGL
#include <gl\glu.h>             // GLU library
#include <math.h>				// Define for sqrt
#include <stdio.h>
#include "resource.h"           // About box resource identifiers.
#include "Scene.h"
#include <thread>				//asyncF

#define glRGB(x, y, z)	glColor3ub((GLubyte)x, (GLubyte)y, (GLubyte)z)
#define BITMAP_ID 0x4D42		// identyfikator formatu BMP
#define GL_PI 3.14

////////////////////////////////////////////////////
static GLfloat xPos = 150.0f;		//wsp drona
static GLfloat yPos = 150.0f;
static GLfloat zPos = 100.0f;
static GLfloat xPosPocz = xPos;
static GLfloat yPosPocz = yPos;
static GLfloat zPosPocz = zPos;
static GLfloat przes = 2.0f;			//,,szybkosc" przesuwania dronem
static GLfloat zoomValueInc = 0.4f;		//,,szybkosc" przyblizania
static GLfloat temp = 0.3f;
static GLfloat prop = 0.3f;
static GLfloat przyblizenie = 5.0f;
static GLfloat rotateVal = 1;			//szybkosc obrotu smigiel
static GLfloat rotateValInc = 4.0f;		//szybkosc zmiany predkosci smigiel
int przyc = 0;							//czy wcisniety jest lewy przycisk myszy(1) lub prawy (-1)

GLfloat xtemp = 0.0f;			//zmienne tymczasowe dla wsp kursora myszki
GLfloat ytemp = 0.0f;

Dron dron;

static GLfloat przedzialCzasowy = 0.1f;

static GLfloat timeStart = 0;		//przedzial czasowy do wzorow
static GLfloat timeInc = 0.01f;

static GLfloat predkoscX = 0;
static GLfloat predkoscY = 0;
static GLfloat predkoscZ = 0;
static GLfloat predkoscPoczatkowaX = 0;
static GLfloat predkoscPoczatkowaY = 0;
static GLfloat predkoscPoczatkowaZ = 0;
static GLfloat drogaX = 0;
static GLfloat drogaY = 0;
static GLfloat drogaZ = 0;

static GLfloat maxPredkosc = 40;
static GLfloat oporPowietrza = 0.996f;
static GLfloat przyspieszenieG = 5;	//5
static GLfloat przyspieszenieCiagu = 0;
static GLfloat przyspieszenieMaxCiagu = 20;
static GLfloat przyspieszenieWypX = 0;
static GLfloat przyspieszenieWypY = 0;
static GLfloat przyspieszenieWypZ = 0;
static GLfloat masa = 0.5f;
//static GLfloat ciag = 0;
//static GLfloat maxCiag = 40;
//static GLfloat silaGrawitacji = grawitacja * masa;
//static GLfloat silaCiagu = 0;
//static GLfloat silaWypadkowa = 0;

static GLfloat droneRotInc = 2.0f;
static GLfloat xDroneRot = 0.0f;	//do obrotu dronem
static GLfloat yDroneRot = 0.0f;
static GLfloat zDroneRot = 0.0f;
////////////////////////////////////////////////////

// Color Palette handle
HPALETTE hPalette = NULL;

// Application name and instance storeage
static LPCTSTR lpszAppName = "GL Template";
static HINSTANCE hInstance;

// Rotation amounts
static GLfloat xRot = 0.0f;
static GLfloat yRot = 0.0f;
static GLfloat zRot = 0.0f;

static GLsizei lastHeight;
static GLsizei lastWidth;

// Opis tekstury
BITMAPINFOHEADER	bitmapInfoHeader;	// nag³ówek obrazu
unsigned char*		bitmapData;			// dane tekstury
unsigned int		texture[2];			// obiekt tekstury


										// Declaration for Window procedure
LRESULT CALLBACK WndProc(HWND    hWnd,
	UINT    message,
	WPARAM  wParam,
	LPARAM  lParam);

// Dialog procedure for about box
BOOL APIENTRY AboutDlgProc(HWND hDlg, UINT message, UINT wParam, LONG lParam);

// Set Pixel Format function - forward declaration
void SetDCPixelFormat(HDC hDC);


void ZapiszNowyStan()
{
	timeStart = 0;

	predkoscPoczatkowaX = predkoscX;
	predkoscPoczatkowaY = predkoscY;
	predkoscPoczatkowaZ = predkoscZ;
	xPosPocz = xPos;
	yPosPocz = yPos;
	zPosPocz = zPos;
	drogaX = 0;
	drogaY = 0;
	drogaZ = 0;
}

void ZablokujPrzechylenie()
{
	if (xDroneRot > 90)
	{
		xDroneRot = 90;
	}
	else if (xDroneRot < -90)
	{
		xDroneRot = -90;
	}

	if (yDroneRot > 90)
	{
		yDroneRot = 90;
	}
	else if (yDroneRot < -90)
	{
		yDroneRot = -90;
	}
}

void UstawKolizje()
{
	GLfloat odleglosc = sqrt(pow(xPos, 2) + pow(yPos, 2));
	GLfloat odlegloscMaxWewn = 322;
	GLfloat odlegloscMaxZewn = 550;
	GLfloat wysokoscPierwszyStopien = 90;
	GLfloat wysokoscOstatniStopien = 190;

	//kolizja z pod³o¿em
	if (zPos < 5.7f)	//6
	{
		zPos = 5.7f;
	}

	//kolizja ze stadionem
	//if(zPos > wysokoscOstatniStopien)	//najwy¿szy stopieñ (powy¿ej stadionu)
	//{
	//	zPos = wysokoscOstatniStopien;
	//	if (odleglosc >= odlegloscMaxZewn)	//ograniczenie przed wyleceniem poza stadion
	//	{
	//		GLfloat kat = atan2(yPos, xPos);
	//		xPos = odlegloscMaxZewn * cos(kat);
	//		yPos = odlegloscMaxZewn * sin(kat);
	//		ZapiszNowyStan();
	//	}
	//}
	//else 
	if ((zPos < wysokoscOstatniStopien && zPos > wysokoscPierwszyStopien))	//œrodkowy stopieñ
	{
		GLfloat katStadionu = atan2((wysokoscOstatniStopien - wysokoscPierwszyStopien),(odlegloscMaxZewn - odlegloscMaxWewn));
		GLfloat odlPrim = (zPos - wysokoscPierwszyStopien) / (tan(katStadionu));
		GLfloat odlegloscAkt = (odlegloscMaxWewn + odlPrim) - 10;
		if (odleglosc > odlegloscAkt)
		{
			float kat = atan2(yPos, xPos);
			xPos = odlegloscAkt * cos(kat);
			yPos = odlegloscAkt * sin(kat);
			predkoscX = 0;
			predkoscY = 0;
			ZapiszNowyStan();
		}
	}
	else if (zPos < wysokoscPierwszyStopien && odleglosc >= odlegloscMaxWewn)	//dolny stopieñ
	{
		GLfloat kat = atan2(yPos, xPos);
		xPos = odlegloscMaxWewn * cos(kat);
		yPos = odlegloscMaxWewn * sin(kat);
		ZapiszNowyStan();
	}

}


// Reduces a normal vector specified as a set of three coordinates,
// to a unit normal vector of length one.
void ReduceToUnit(float vector[3])
{
	float length;

	// Calculate the length of the vector		
	length = (float)sqrt((vector[0] * vector[0]) +
		(vector[1] * vector[1]) +
		(vector[2] * vector[2]));

	// Keep the program from blowing up by providing an exceptable
	// value for vectors that may calculated too close to zero.
	if (length == 0.0f)
		length = 1.0f;

	// Dividing each element by the length will result in a
	// unit normal vector.
	vector[0] /= length;
	vector[1] /= length;
	vector[2] /= length;
}


// Points p1, p2, & p3 specified in counter clock-wise order
void calcNormal(float v[3][3], float out[3])
{
	float v1[3], v2[3];
	static const int x = 0;
	static const int y = 1;
	static const int z = 2;

	// Calculate two vectors from the three points
	v1[x] = v[0][x] - v[1][x];
	v1[y] = v[0][y] - v[1][y];
	v1[z] = v[0][z] - v[1][z];

	v2[x] = v[1][x] - v[2][x];
	v2[y] = v[1][y] - v[2][y];
	v2[z] = v[1][z] - v[2][z];

	// Take the cross product of the two vectors to get
	// the normal vector which will be stored in out
	out[x] = v1[y] * v2[z] - v1[z] * v2[y];
	out[y] = v1[z] * v2[x] - v1[x] * v2[z];
	out[z] = v1[x] * v2[y] - v1[y] * v2[x];

	// Normalize the vector (shorten length to one)
	ReduceToUnit(out);
}



// Change viewing volume and viewport.  Called when window is resized
void ChangeSize(GLsizei w, GLsizei h)
{
	GLfloat nRange = 100.0f;
	GLfloat fAspect;
	// Prevent a divide by zero
	if (h == 0)
		h = 1;

	lastWidth = w;
	lastHeight = h;

	fAspect = (GLfloat)w / (GLfloat)h;
	// Set Viewport to window dimensions
	glViewport(0, 0, w, h);

	// Reset coordinate system
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	// Establish clipping volume (left, right, bottom, top, near, far)
	if (w <= h)
		glOrtho(-nRange, nRange, -nRange*h / w, nRange*h / w, -nRange, nRange);
	else
		glOrtho(-nRange*w / h, nRange*w / h, -nRange, nRange, -1000, 1000);

	// Establish perspective: 
	/*
	gluPerspective(60.0f,fAspect,1.0,400);
	*/

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}



// This function does any needed initialization on the rendering
// context.  Here it sets up and initializes the lighting for
// the scene.
void SetupRC()
{
	// Light values and coordinates
	//GLfloat  ambientLight[] = { 0.3f, 0.3f, 0.3f, 1.0f };
	//GLfloat  diffuseLight[] = { 0.7f, 0.7f, 0.7f, 1.0f };
	//GLfloat  specular[] = { 1.0f, 1.0f, 1.0f, 1.0f};
	//GLfloat	 lightPos[] = { 0.0f, 170.0f, 170.0f, 1.0f };
	//GLfloat  specref[] =  { 1.0f, 1.0f, 1.0f, 1.0f };


	glEnable(GL_DEPTH_TEST);	// Hidden surface removal
	glFrontFace(GL_CCW);		// Counter clock-wise polygons face out
								//glEnable(GL_CULL_FACE);		// Do not calculate inside of jet

								// Enable lighting
								//glEnable(GL_LIGHTING);

								// Setup and enable light 0
								//glLightfv(GL_LIGHT0,GL_AMBIENT,ambientLight);
								//glLightfv(GL_LIGHT0,GL_DIFFUSE,diffuseLight);
								//glLightfv(GL_LIGHT0,GL_SPECULAR,specular);
								//glLightfv(GL_LIGHT0,GL_POSITION,lightPos);
								//glEnable(GL_LIGHT0);

								// Enable color tracking
								//glEnable(GL_COLOR_MATERIAL);

								// Set Material properties to follow glColor values
								//glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);

								// All materials hereafter have full specular reflectivity
								// with a high shine
								//glMaterialfv(GL_FRONT, GL_SPECULAR,specref);
								//glMateriali(GL_FRONT,GL_SHININESS,128);


								// White background
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	// Black brush
	glColor3f(0.0, 0.0, 0.0);
}



// LoadBitmapFile
// opis: ³aduje mapê bitow¹ z pliku i zwraca jej adres.
//       Wype³nia strukturê nag³ówka.
//	 Nie obs³uguje map 8-bitowych.
 static unsigned char *LoadBitmapFile(char *filename, BITMAPINFOHEADER *bitmapInfoHeader)
{
	FILE *filePtr;							// wskaŸnik pozycji pliku
	BITMAPFILEHEADER	bitmapFileHeader;		// nag³ówek pliku
	unsigned char		*bitmapImage;			// dane obrazu
	int					imageIdx = 0;		// licznik pikseli
	unsigned char		tempRGB;				// zmienna zamiany sk³adowych

												// otwiera plik w trybie "read binary"
	filePtr = fopen(filename, "rb");
	if (filePtr == NULL)
		return NULL;

	// wczytuje nag³ówek pliku
	fread(&bitmapFileHeader, sizeof(BITMAPFILEHEADER), 1, filePtr);

	// sprawdza, czy jest to plik formatu BMP
	if (bitmapFileHeader.bfType != BITMAP_ID)
	{
		fclose(filePtr);
		return NULL;
	}

	// wczytuje nag³ówek obrazu
	fread(bitmapInfoHeader, sizeof(BITMAPINFOHEADER), 1, filePtr);

	// ustawia wskaŸnik pozycji pliku na pocz¹tku danych obrazu
	fseek(filePtr, bitmapFileHeader.bfOffBits, SEEK_SET);

	// przydziela pamiêæ buforowi obrazu
	bitmapImage = (unsigned char*)malloc(bitmapInfoHeader->biSizeImage);

	// sprawdza, czy uda³o siê przydzieliæ pamiêæ
	if (!bitmapImage)
	{
		free(bitmapImage);
		fclose(filePtr);
		return NULL;
	}

	// wczytuje dane obrazu
	fread(bitmapImage, 1, bitmapInfoHeader->biSizeImage, filePtr);

	// sprawdza, czy dane zosta³y wczytane
	if (bitmapImage == NULL)
	{
		fclose(filePtr);
		return NULL;
	}

	// zamienia miejscami sk³adowe R i B 
	for (imageIdx = 0; imageIdx < bitmapInfoHeader->biSizeImage; imageIdx += 3)
	{
		tempRGB = bitmapImage[imageIdx];
		bitmapImage[imageIdx] = bitmapImage[imageIdx + 2];
		bitmapImage[imageIdx + 2] = tempRGB;
	}

	// zamyka plik i zwraca wskaŸnik bufora zawieraj¹cego wczytany obraz
	fclose(filePtr);
	return bitmapImage;
}


// Called to draw scene
void RenderScene(void)
{
	//float normal[3];	// Storeage for calculated surface normal

	// Clear the window with current clearing color
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// Save the matrix state and do the rotations
	glPushMatrix();
	glRotatef(xRot, 1.0f, 0.0f, 0.0f);
	glRotatef(yRot, 0.0f, 1.0f, 0.0f);
	glRotatef(zRot, 0.0f, 0.0f, 1.0f);
	/////////////////////////////////////////////////////////////////
	// MIEJSCE NA KOD OPENGL DO TWORZENIA WLASNYCH SCEN:		   //
	/////////////////////////////////////////////////////////////////


	//Sposób na odróŸnienie "przedniej" i "tylniej" œciany wielok¹ta:
	glPolygonMode(GL_BACK, GL_LINE);

	glScaled(przyblizenie, przyblizenie, przyblizenie);
	/*Scene scene(xPos, yPos, zPos, przyblizenie, xDroneRot, yDroneRot);
	scene.RenderScene();*/

	///////////////////////////////////////////////////////////////////
	//

	/*gluLookAt(4 + xPos*prop, 4 + yPos*prop, 4 + zPos*prop,
		xPos*prop, yPos*prop, zPos*prop,
		0, 0, 1);*/
	gluLookAt(xPos*prop, 4 + yPos*prop, 4 + zPos*prop,
		xPos*prop, yPos*prop, zPos*prop,
		0, 0, 1);

	Coordinate coordinate(true);
	//coordinate.Draw();
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);


	glPushMatrix();
	glScaled(prop, prop, prop);
	//glTranslated(xPos, yPos, zPos);
	//glTranslated(xPos, yPos, zPos);
	//glRotatef(xDroneRot, 1, 0, 0);
	//glRotatef(yDroneRot, 0, 1, 0);
	


	dron.ChangePosition(xPos, yPos, zPos);
	dron.ChangeRotation(xDroneRot, yDroneRot, zDroneRot);
	dron.Draw();
	glPopMatrix();
	
	Stadion stadion;
	stadion.Rysuj();

	Bieznia bieznia;
	bieznia.Rysuj(100, 60);
	
	//
	///////////////////////////////////////////////////////////////////




	//szescian();
	//ukl_wsp();

	//GLfloat sa[3] = { 10,20,30 };
	//GLfloat sa2[3] = { 20,40,30 }; //30 };
	//GLfloat sa4[3] = { -10,-5,30 }; //30 };
	//stozek(sa, 10, 40, 15, 10);
	//rysujWalec(sa2, 1, 60);
	//rysujWalec(sa4, 1, 60);


	//Uzyskanie siatki:
	//glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);

	/////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);

	// Flush drawing commands
	glFlush();
}


// Select the pixel format for a given device context
void SetDCPixelFormat(HDC hDC)
{
	int nPixelFormat;

	static PIXELFORMATDESCRIPTOR pfd = {
		sizeof(PIXELFORMATDESCRIPTOR),  // Size of this structure
		1,                                                              // Version of this structure    
		PFD_DRAW_TO_WINDOW |                    // Draw to Window (not to bitmap)
		PFD_SUPPORT_OPENGL |					// Support OpenGL calls in window
		PFD_DOUBLEBUFFER,                       // Double buffered
		PFD_TYPE_RGBA,                          // RGBA Color mode
		24,                                     // Want 24bit color 
		0,0,0,0,0,0,                            // Not used to select mode
		0,0,                                    // Not used to select mode
		0,0,0,0,0,                              // Not used to select mode
		32,                                     // Size of depth buffer
		0,                                      // Not used to select mode
		0,                                      // Not used to select mode
		PFD_MAIN_PLANE,                         // Draw in main plane
		0,                                      // Not used to select mode
		0,0,0 };                                // Not used to select mode

												// Choose a pixel format that best matches that described in pfd
	nPixelFormat = ChoosePixelFormat(hDC, &pfd);

	// Set the pixel format for the device context
	SetPixelFormat(hDC, nPixelFormat, &pfd);
}



// If necessary, creates a 3-3-2 palette for the device context listed.
HPALETTE GetOpenGLPalette(HDC hDC)
{
	HPALETTE hRetPal = NULL;	// Handle to palette to be created
	PIXELFORMATDESCRIPTOR pfd;	// Pixel Format Descriptor
	LOGPALETTE *pPal;			// Pointer to memory for logical palette
	int nPixelFormat;			// Pixel format index
	int nColors;				// Number of entries in palette
	int i;						// Counting variable
	BYTE RedRange, GreenRange, BlueRange;
	// Range for each color entry (7,7,and 3)


	// Get the pixel format index and retrieve the pixel format description
	nPixelFormat = GetPixelFormat(hDC);
	DescribePixelFormat(hDC, nPixelFormat, sizeof(PIXELFORMATDESCRIPTOR), &pfd);

	// Does this pixel format require a palette?  If not, do not create a
	// palette and just return NULL
	if (!(pfd.dwFlags & PFD_NEED_PALETTE))
		return NULL;

	// Number of entries in palette.  8 bits yeilds 256 entries
	nColors = 1 << pfd.cColorBits;

	// Allocate space for a logical palette structure plus all the palette entries
	pPal = (LOGPALETTE*)malloc(sizeof(LOGPALETTE) + nColors * sizeof(PALETTEENTRY));

	// Fill in palette header 
	pPal->palVersion = 0x300;		// Windows 3.0
	pPal->palNumEntries = nColors; // table size

								   // Build mask of all 1's.  This creates a number represented by having
								   // the low order x bits set, where x = pfd.cRedBits, pfd.cGreenBits, and
								   // pfd.cBlueBits.  
	RedRange = (1 << pfd.cRedBits) - 1;
	GreenRange = (1 << pfd.cGreenBits) - 1;
	BlueRange = (1 << pfd.cBlueBits) - 1;

	// Loop through all the palette entries
	for (i = 0; i < nColors; i++)
	{
		// Fill in the 8-bit equivalents for each component
		pPal->palPalEntry[i].peRed = (i >> pfd.cRedShift) & RedRange;
		pPal->palPalEntry[i].peRed = (unsigned char)(
			(double)pPal->palPalEntry[i].peRed * 255.0 / RedRange);

		pPal->palPalEntry[i].peGreen = (i >> pfd.cGreenShift) & GreenRange;
		pPal->palPalEntry[i].peGreen = (unsigned char)(
			(double)pPal->palPalEntry[i].peGreen * 255.0 / GreenRange);

		pPal->palPalEntry[i].peBlue = (i >> pfd.cBlueShift) & BlueRange;
		pPal->palPalEntry[i].peBlue = (unsigned char)(
			(double)pPal->palPalEntry[i].peBlue * 255.0 / BlueRange);

		pPal->palPalEntry[i].peFlags = (unsigned char)NULL;
	}


	// Create the palette
	hRetPal = CreatePalette(pPal);

	// Go ahead and select and realize the palette for this device context
	SelectPalette(hDC, hRetPal, FALSE);
	RealizePalette(hDC);

	// Free the memory used for the logical palette structure
	free(pPal);

	// Return the handle to the new palette
	return hRetPal;
}


void task(int time)	//asyncF
{
	while (1)
	{
		//double radian = 3.1415 / 180;
		std::this_thread::sleep_for(std::chrono::milliseconds(time));
		/*xPos += -2;*/
		//timeStart += timeInc;
		timeStart += 0.01f;
		zDroneRot = -atan2(xDroneRot, yDroneRot) / (3.14f / 180.0f) - 90;

		//przyspieszenieWypX = (przyspieszenieCiagu * cos(yDroneRot * 3.14f / 180.0f)) / masa;
		//przyspieszenieWypY = (przyspieszenieCiagu * cos(xDroneRot * 3.14f / 180.0f));
		//przyspieszenieWypZ = abs(pow(przyspieszenieWypX, 2) + pow(przyspieszenieWypY, 2));
		//przyspieszenieWypZ = abs(pow(przyspieszenieCiagu,2)-pow(abs(pow(przyspieszenieWypX, 2) + pow(przyspieszenieWypY, 2)),2));

		
		//zDroneRot = 45;

		//przyspieszenieWypZ = (przyspieszenieCiagu * sin(xDroneRot * 3.14f / 180.0f) + przyspieszenieCiagu * cos(yDroneRot * 3.14f / 180.0f)) / masa;
		//zDroneRot = atan2(xDroneRot, yDroneRot)/ radian;

		//
		//przyspieszenieWypZ = (przyspieszenieCiagu - przyspieszenieG)/masa;	//Fw = (Fc-Fg)/m -> F=a/m
		//

		//przyspieszenieWypZ = (przyspieszenieCiagu - przyspieszenieG) / masa;	//Fw = (Fc-Fg)/m -> F=a/m
		////przyspieszenieWypadkowe = (przyspieszenieCiagu - przyspieszenieG);
		//predkoscZ = predkoscPoczatkowaZ + przyspieszenieWypZ * timeStart;	//v(t)
		//drogaZ = predkoscPoczatkowaZ*timeStart + (przyspieszenieWypZ*timeStart*timeStart)/2.0f;	//s(t)
		//zPos = zPosPocz + drogaZ;
		if(timeStart>0 ){
			przyspieszenieWypX = (przyspieszenieCiagu * cos((yDroneRot-90)* 3.14f / 180.0f)) / masa;
			//przyspieszenieWypX = (przyspieszenieCiagu * yDroneRot * 3.14f / 180.0f) / masa;
			
			predkoscX = (predkoscPoczatkowaX * oporPowietrza + przyspieszenieWypX * timeStart);	//v(t)
			if (abs(predkoscX) > maxPredkosc)
			{
				if (predkoscX > 0)
				{
					predkoscX = maxPredkosc;
				}
				else
				{
					predkoscX = -maxPredkosc;
				}
			}
			drogaX = predkoscPoczatkowaX*timeStart + (przyspieszenieWypX*timeStart*timeStart) / 2.0f;
			xPos = xPosPocz + drogaX;


			przyspieszenieWypY = (przyspieszenieCiagu * cos((xDroneRot + 90)* 3.14f / 180.0f)) / masa;
			predkoscY = (predkoscPoczatkowaY * oporPowietrza + przyspieszenieWypY * timeStart);	//v(t)
			if (abs(predkoscY) > maxPredkosc)
			{
				if (predkoscY > 0)
				{
					predkoscY = maxPredkosc;
				}
				else
				{
					predkoscY = -maxPredkosc;
				}
			}
			drogaY = predkoscPoczatkowaY*timeStart + (przyspieszenieWypY*timeStart*timeStart) / 2.0f;
			yPos = yPosPocz + drogaY;



			/*if (przyspieszenieCiagu > 0)
			{
				przyspieszenieWypZ = abs(pow(przyspieszenieCiagu, 2) - pow(abs(pow(przyspieszenieWypX, 2) + pow(przyspieszenieWypY, 2)), 2));
			}
			else
			{
				przyspieszenieWypZ = -abs(pow(przyspieszenieCiagu, 2) - pow(abs(pow(przyspieszenieWypX, 2) + pow(przyspieszenieWypY, 2)), 2));
			}*/
			
			/*if(abs(xDroneRot) == 0 && abs(yDroneRot) == 0)
			{
				przyspieszenieWypZ = ((przyspieszenieCiagu) - przyspieszenieG) / masa;
			}
			else
			{*/
				
			//}

			/*else if (abs(yDroneRot) > 0 && abs(xDroneRot) > 0)
			{
				przyspieszenieWypZ = ((przyspieszenieCiagu * sin((xDroneRot + 90)* 3.14f / 180.0f)) - przyspieszenieG) / masa;
			}*/
			/*else if (abs(xDroneRot) > 0)
			{
				przyspieszenieWypZ = ((przyspieszenieCiagu * sin((xDroneRot + 90)* 3.14f / 180.0f)) - przyspieszenieG) / masa;
			}
			else if (abs(yDroneRot) > 0)
			{
				przyspieszenieWypZ = ((przyspieszenieCiagu * sin((yDroneRot + 90)* 3.14f / 180.0f)) - przyspieszenieG) / masa;
			}*/

			przyspieszenieWypZ = ((przyspieszenieCiagu *
				sin((yDroneRot + 90)* 3.14f / 180.0f) *
				sin((xDroneRot + 90)* 3.14f / 180.0f)) - przyspieszenieG) / masa;

			predkoscZ = (predkoscPoczatkowaZ * oporPowietrza + (przyspieszenieWypZ) * timeStart);	//v(t)
			if (abs(predkoscZ) > maxPredkosc)
			{
				if (predkoscZ > 0)
				{
					predkoscZ = maxPredkosc;
				}
				else
				{
					predkoscZ = -maxPredkosc;
				}
			}
			drogaZ = predkoscPoczatkowaZ*timeStart + (przyspieszenieWypZ*timeStart*timeStart) / 2.0f;
			zPos = zPosPocz + drogaZ;


		}
		ZapiszNowyStan();
		UstawKolizje();
	}
	//std::thread bt(task, 1);	//asyncF
	//bt.join();
}


// Entry point of all Windows programs
int APIENTRY WinMain(HINSTANCE       hInst,
	HINSTANCE       hPrevInstance,
	LPSTR           lpCmdLine,
	int                     nCmdShow)
{
	MSG                     msg;            // Windows message structure
	WNDCLASS        wc;                     // Windows class structure
	HWND            hWnd;           // Storeage for window handle

	hInstance = hInst;

	////////////////////////////////////////////////////////////////
	///////
	std::thread bt(task,10);	//asyncF
	///////
	////////////////////////////////////////////////////////////////

	// Register Window style
	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.lpfnWndProc = (WNDPROC)WndProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = hInstance;
	wc.hIcon = NULL;
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);

	// No need for background brush for OpenGL window
	wc.hbrBackground = NULL;

	wc.lpszMenuName = MAKEINTRESOURCE(IDR_MENU);
	wc.lpszClassName = lpszAppName;

	// Register the window class
	if (RegisterClass(&wc) == 0)
		return FALSE;


	// Create the main application window
	hWnd = CreateWindow(
		lpszAppName,
		lpszAppName,

		// OpenGL requires WS_CLIPCHILDREN and WS_CLIPSIBLINGS
		WS_OVERLAPPEDWINDOW | WS_CLIPCHILDREN | WS_CLIPSIBLINGS,

		// Window position and size
		50, 50,
		400, 400,
		NULL,
		NULL,
		hInstance,
		NULL);

	// If window was not created, quit
	if (hWnd == NULL)
		return FALSE;


	// Display the window
	ShowWindow(hWnd, SW_SHOW);
	UpdateWindow(hWnd);

	// Process application messages until the application closes
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	bt.join();
	return msg.wParam;
}




// Window procedure, handles all messages for this program
LRESULT CALLBACK WndProc(HWND    hWnd,
	UINT    message,
	WPARAM  wParam,
	LPARAM  lParam)
{
	static HGLRC hRC;               // Permenant Rendering context
	static HDC hDC;                 // Private GDI Device context

	switch (message)
	{
		case WM_TIMER:
			if (wParam == 100)
			{
				//timeStart += 0.01f;
				//przyspieszenieWypX = (przyspieszenieCiagu * yDroneRot * 3.14f / 180.0f) / masa;
				//predkoscX = predkoscPoczatkowaX + przyspieszenieWypX * timeStart;	//v(t)
				//drogaX = predkoscPoczatkowaX*timeStart + (przyspieszenieWypX*timeStart*timeStart) / 2.0f;
				//xPos = xPosPocz + drogaX;


				//zDroneRot = 45;
				/*if (timeStart == 0)
				{
				predkoscPoczatkowa = predkosc;
				zPosPocz = zPos;
				droga = 0;
				timeStart += timeInc;
				}
				else
				{
				timeStart += timeInc;
				}*/
				//timeStart += timeInc;

				//xPos += przes;
				//GLfloat silaWypadkowa = silaCiagu - silaGrawitacji; //Fw = Fc-Fg
				//zPos += (silaWypadkowa*0.1f*0.1f)/2;				//s = (a*t^2)/2
				InvalidateRect(hWnd, NULL, true);
			}
			break;
		// Window creation, setup for OpenGL
	case WM_CREATE:
		SetTimer(hWnd, 100, 20, NULL);
		// Store the device context
		hDC = GetDC(hWnd);

		// Select the pixel format
		SetDCPixelFormat(hDC);

		// Create palette if needed
		hPalette = GetOpenGLPalette(hDC);

		// Create the rendering context and make it current
		hRC = wglCreateContext(hDC);
		wglMakeCurrent(hDC, hRC);
		SetupRC();
		glGenTextures(2, &texture[0]);                  // tworzy obiekt tekstury			

														// ³aduje pierwszy obraz tekstury:
		bitmapData = LoadBitmapFile("Bitmapy\\checker.bmp", &bitmapInfoHeader);

		glBindTexture(GL_TEXTURE_2D, texture[0]);       // aktywuje obiekt tekstury



		// ³aduje drugi obraz tekstury:
		bitmapData = LoadBitmapFile("Bitmapy\\crate.bmp", &bitmapInfoHeader);
		glBindTexture(GL_TEXTURE_2D, texture[1]);       // aktywuje obiekt tekstury



		// ustalenie sposobu mieszania tekstury z t³em
		glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
		break;

		// Window is being destroyed, cleanup
	case WM_DESTROY:
		// Deselect the current rendering context and delete it
		wglMakeCurrent(hDC, NULL);
		wglDeleteContext(hRC);

		// Delete the palette if it was created
		if (hPalette != NULL)
			DeleteObject(hPalette);

		// Tell the application to terminate after the window
		// is gone.
		PostQuitMessage(0);
		break;

		// Window is resized.
	case WM_SIZE:
		// Call our function which modifies the clipping
		// volume and viewport
		ChangeSize(LOWORD(lParam), HIWORD(lParam));
		break;


		// The painting function.  This message sent by Windows 
		// whenever the screen needs updating.
	case WM_PAINT:
	{
		// Call OpenGL drawing code
		RenderScene();

		SwapBuffers(hDC);

		// Validate the newly painted client area
		ValidateRect(hWnd, NULL);
	}
	break;

	// Windows is telling the application that it may modify
	// the system palette.  This message in essance asks the 
	// application for a new palette.
	case WM_QUERYNEWPALETTE:
		// If the palette was created.
		if (hPalette)
		{
			int nRet;

			// Selects the palette into the current device context
			SelectPalette(hDC, hPalette, FALSE);

			// Map entries from the currently selected palette to
			// the system palette.  The return value is the number 
			// of palette entries modified.
			nRet = RealizePalette(hDC);

			// Repaint, forces remap of palette in current window
			InvalidateRect(hWnd, NULL, FALSE);

			return nRet;
		}
		break;


		// This window may set the palette, even though it is not the 
		// currently active window.
	case WM_PALETTECHANGED:
		// Don't do anything if the palette does not exist, or if
		// this is the window that changed the palette.
		if ((hPalette != NULL) && ((HWND)wParam != hWnd))
		{
			// Select the palette into the device context
			SelectPalette(hDC, hPalette, FALSE);

			// Map entries to system palette
			RealizePalette(hDC);

			// Remap the current colors to the newly realized palette
			UpdateColors(hDC);
			return 0;
		}
		break;

		// Key press, check for arrow keys to do cube rotation.
	case WM_KEYDOWN:
	{
		/*if (wParam == VK_UP)
		xRot -= 5.0f;

		if (wParam == VK_DOWN)
		xRot += 5.0f;

		if (wParam == VK_LEFT)
		yRot -= 5.0f;

		if (wParam == VK_RIGHT)
		yRot += 5.0f;*/

		przes = 4.0f;

		//sterowanie pozycj¹ drona
		if (wParam == 'd' || wParam == 'D') //(wParam == 'b' || wParam == 'B')
		{
			xPos += przes;
		}

		if (wParam == 'w' || wParam == 'W') //(wParam == 'n' || wParam == 'N')
		{
			yPos += przes;
		}

		if (wParam == 'e' || wParam == 'E') //(wParam == 'm' || wParam == 'M')
		{
			zPos += przes;
		}

		if (wParam == 'a' || wParam == 'A') //(wParam == 'j' || wParam == 'J')
		{
			xPos -= przes;
		}

		if (wParam == 's' || wParam == 'S') //(wParam == 'k' || wParam == 'K')
		{
			yPos -= przes;
		}

		if (wParam == 'q' || wParam == 'Q') //(wParam == 'l' || wParam == 'L')
		{
			zPos -= przes;
		}

		//sterowanie ,,pochyleniem" kamery
		if (wParam == 'u' || wParam == 'U')
		{
			yRot -= 5.0f;
		}

		if (wParam == 'j' || wParam == 'J')
		{
			yRot += 5.0f;
		}

		if (wParam == 'h' || wParam == 'H')
		{
			xRot -= 5.0f;
		}

		if (wParam == 'k' || wParam == 'K')
		{
			xRot += 5.0f;
		}

		if (wParam == 'y' || wParam == 'Y')
		{
			zRot -= 5.0f;
		}

		if (wParam == 'i' || wParam == 'I')
		{
			zRot += 5.0f;
		}

		//sterowanie obrotami silnika
		if (wParam == 'o' || wParam == 'O')	//zwiekszanie obrotów silnikow
		{
			if (rotateVal + rotateValInc <= 84)
			{
				rotateVal += rotateValInc;
				przyspieszenieCiagu = (rotateVal / 84.0f) * przyspieszenieMaxCiagu;	//obliczenie sily/przyspieszenia ciagu
				

				ZapiszNowyStan();
			}
			dron.SetRotate(rotateVal);
		}

		if (wParam == 'p' || wParam == 'P')	//zmniejszanie obrotów silnikow
		{
			if (rotateVal - rotateValInc >= -84)
			{
				rotateVal -= rotateValInc;
				przyspieszenieCiagu = (rotateVal / 84.0f) * przyspieszenieMaxCiagu; //obliczenie sily/przyspieszenia ciagu
				
				ZapiszNowyStan();
			}
			/*else
			{
				rotateVal = 0;
				przyspieszenieCiagu = 0;
			}*/
			dron.SetRotate(rotateVal);
		}

		
		//sterowanie pochyleniem drona
		if (wParam == VK_UP)
		{
			xDroneRot += droneRotInc;
		}

		if (wParam == VK_DOWN)
		{
			xDroneRot -= droneRotInc;
		}

		if (wParam == VK_LEFT)
		{
			yDroneRot += droneRotInc;
		}

		if (wParam == VK_RIGHT)
		{
			yDroneRot -= droneRotInc;
		}

		ZablokujPrzechylenie();


		/*if (wParam == 'o' || wParam == 'O')
		{
		przyblizenie -= 0.1f;
		}

		if (wParam == 'p' || wParam == 'P')
		{
		przyblizenie += 0.1f;
		}*/

	
		/*if (wParam == WM_MOUSEWHEEL)
		{
			przyblizenie += 0.1f;
		}*/


		xRot = (const int)xRot % 360;
		yRot = (const int)yRot % 360;

		//Test();
		InvalidateRect(hWnd, NULL, FALSE);
	}
	break;


	case WM_MOUSEWHEEL:
	{

		if (GET_WHEEL_DELTA_WPARAM(wParam) > 0)
		{
			przyblizenie += zoomValueInc;
		}
		else
		{
			przyblizenie -= zoomValueInc;
		}

		InvalidateRect(hWnd, NULL, FALSE);
	}
	break;

	case WM_LBUTTONDOWN:
	{
		przyc = 1;
		xtemp = LOWORD(lParam);
		ytemp = HIWORD(lParam);
	}
	break;

	case WM_LBUTTONUP:
	{
		przyc = 0;
	}
	break;

	case WM_RBUTTONDOWN:
	{
		przyc = -1;
		xtemp = LOWORD(lParam);
		ytemp = HIWORD(lParam);
	}
	break;

	case WM_RBUTTONUP:
	{
		przyc = 0;
	}
	break;

	case WM_MOUSEMOVE:
	{
		if (przyc==1)
		{
			GLfloat skala = 0.1f;

			/*if ((HIWORD(lParam) - ytemp) >= 0)
			{
			xRot += skala;
			}
			else
			{
			xRot -= skala;
			}

			if ((LOWORD(lParam) - xtemp) >= 0)
			{
			yRot += skala;
			}
			else
			{
			yRot -= skala;
			}*/

			xRot += (HIWORD(lParam) - ytemp)*skala;
			yRot += (LOWORD(lParam) - xtemp)*skala;
			xtemp = LOWORD(lParam);
			ytemp = HIWORD(lParam);

			//Test();
			//ZapiszNowyStan();
			InvalidateRect(hWnd, NULL, FALSE);
		}
		else if(przyc == -1)	//srterowanie pochyleniem prawym przyciskiem myszy
		{
			GLfloat skala = 0.2f;
			//xDroneRot
			xDroneRot -= (HIWORD(lParam) - ytemp)*skala;
			yDroneRot -= (LOWORD(lParam) - xtemp)*skala;
			xtemp = LOWORD(lParam);
			ytemp = HIWORD(lParam);

			ZablokujPrzechylenie();

			//Test();
			//ZapiszNowyStan();
			InvalidateRect(hWnd, NULL, FALSE);
		}
		
	}
	break;

	// A menu command
	case WM_COMMAND:
	{
		switch (LOWORD(wParam))
		{
			// Exit the program
		case ID_FILE_EXIT:
			DestroyWindow(hWnd);
			break;

			// Display the about box

		}
	}
	break;


	default:   // Passes it on if unproccessed
		return (DefWindowProc(hWnd, message, wParam, lParam));

	}

	return (0L);
}




// Dialog procedure.
BOOL APIENTRY AboutDlgProc(HWND hDlg, UINT message, UINT wParam, LONG lParam)
{

	switch (message)
	{
		// Initialize the dialog box
	case WM_INITDIALOG:
	{
		//	int i;
		//	GLenum glError;

		//	// glGetString demo
		//	SetDlgItemText(hDlg, IDC_OPENGL_VENDOR, glGetString(GL_VENDOR));
		//	SetDlgItemText(hDlg, IDC_OPENGL_RENDERER, glGetString(GL_RENDERER));
		//	SetDlgItemText(hDlg, IDC_OPENGL_VERSION, glGetString(GL_VERSION));
		//	SetDlgItemText(hDlg, IDC_OPENGL_EXTENSIONS, glGetString(GL_EXTENSIONS));

		//	// gluGetString demo
		//	SetDlgItemText(hDlg, IDC_GLU_VERSION, gluGetString(GLU_VERSION));
		//	SetDlgItemText(hDlg, IDC_GLU_EXTENSIONS, gluGetString(GLU_EXTENSIONS));


		//	// Display any recent error messages
		//	i = 0;
		//	do {
		//		glError = glGetError();
		//		SetDlgItemText(hDlg, IDC_ERROR1 + i, gluErrorString(glError));
		//		i++;
		//	} while (i < 6 && glError != GL_NO_ERROR);


		//	return (TRUE);
	}
	break;

	// Process command messages
	case WM_COMMAND:
	{
		// Validate and Make the changes
		if (LOWORD(wParam) == IDOK)
			EndDialog(hDlg, TRUE);
	}
	break;

	// Closed from sysbox
	case WM_CLOSE:
		EndDialog(hDlg, TRUE);
		break;
	}

	return FALSE;
}