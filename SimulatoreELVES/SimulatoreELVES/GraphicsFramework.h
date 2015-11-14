// GraphicsFramework.h

#ifndef GRAPHICSFRAMEWORK_H
#define GRAPHICSFRAMEWORK_H

#include <windows.h>        // must include this for windows programs

// A graphics framework class used to implement a drawing area within a windows control.
// This class implements a back buffer as a memory bitmap which will store pixels and then
// copy them with a call to the Draw method.
class GraphicsFramework {
private:
	HBITMAP     memBMP;					// back buffer
	HDC         memHDC;
	HANDLE oldHDC;
	int wd, ht;
	int wdOver2;
	int htOver2;
	RECT rect;                          // rect for this window
	HWND hwnd;							// handle to the output control

public:
	GraphicsFramework() {
		this->hwnd = NULL;
	}

	// construct from a windows handle
	GraphicsFramework(HWND hwnd) {
		BITMAPINFO bmi;					// bitmap info structure for creating the back buffer
		HDC hdc;

		this->hwnd = hwnd;

		// get the window's client rectangle and its center
		hdc = GetDC(hwnd);
		GetClientRect(hwnd, &rect);
		wd = rect.right - rect.left;
		ht = rect.bottom - rect.top;
		wdOver2 = wd / 2;
		htOver2 = ht / 2;

		// set up a 32bit rgb dib for an offscreen (memory) render target (the back buffer)
		memHDC = CreateCompatibleDC(hdc);
		bmi.bmiHeader.biWidth = wd;
		bmi.bmiHeader.biHeight = ht;
		bmi.bmiHeader.biBitCount = 32;
		bmi.bmiHeader.biCompression = BI_RGB;
		bmi.bmiHeader.biClrUsed = 0;
		bmi.bmiHeader.biClrImportant = 0;
		bmi.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
		bmi.bmiHeader.biPlanes = 1;
		bmi.bmiHeader.biSizeImage = 0;

		memBMP = CreateDIBSection(memHDC, &bmi, DIB_RGB_COLORS, NULL, NULL, 0);

		// select this memory bmp for drawing
		// note: it will remain selected until destructor is called
		oldHDC = SelectObject(memHDC, memBMP);

		// release the device context
		ReleaseDC(hwnd, hdc);
	}

	~GraphicsFramework() {
		// deselect and delete the memory dc that was selected in the constructor
		SelectObject(memHDC, oldHDC);
		DeleteObject(memBMP);
		DeleteDC(memHDC);
	}

	// this method copies the back buffer to the output window
	void Draw()    {
		HDC graphics;                       // graphics device context

		graphics = GetDC(hwnd);

		// copy from offscreen memory bmp to screen
		BitBlt(graphics, 0, 0, wd, ht, memHDC, 0, 0, SRCCOPY);

		// release the device context
		ReleaseDC(hwnd, graphics);
	}

	void DrawPixel(int x, int y, COLORREF color) {
		if (x  < -wdOver2 || x >= wdOver2 ||
			y <= -htOver2 || y >  htOver2)
		{
			// x and/or y is out of bounds so don't draw

		}
		else {
			// move origin from upper left to center of buffer
			// draw the pixel 
			SetPixel(memHDC, wdOver2 + x, htOver2 - y, color);
		}
	}

	void ClearScene(COLORREF backColor)
	{
		// clear the offscreen memory bmp to backColor
		HBRUSH hBrush;

		// create the brush with specified color
		hBrush = CreateSolidBrush(backColor);

		// fill the rectangle with black
		rect.left = 0;
		rect.right = wd;
		rect.top = 0;
		rect.bottom = ht;
		FillRect(memHDC, &rect, hBrush);

		// release the brush
		DeleteObject(hBrush);
	}

	// add a point to be drawn
	void AddPoint(int x, int y, COLORREF color) {
		SetPixel(memHDC, wdOver2 + x, htOver2 - y, color);
	}

	// draw x and y axis in specifice color, with single dot every tic step
	void AddAxis(COLORREF color, int ticStep) {
		int x, y;

		// draw horizontal line
		for (x = -wdOver2; x <= wdOver2; x++) {
			if (x % ticStep == 0)     {
				//pList.Add(x, 0, color);
				DrawPixel(x, 0, color);

			}
		}

		// draw vertical line
		for (y = -htOver2; y < htOver2; y++) {
			if (y % ticStep == 0){
				//pList.Add(0, y, color);
				DrawPixel(0, y, color);

			}
		}
	}
};

#endif
