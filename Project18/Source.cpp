#include <Windows.h>
#include <tchar.h>
#include "resource.h"

BOOL CALLBACK DlgProc(HWND, UINT, WPARAM, LPARAM);

HWND hB, hName, hDate, hBar;
short correctAnswer = NULL; short maxAnswer = 8;
TCHAR str[50], name[20], date[20];
TCHAR percent[] = TEXT("%");

int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInst, LPTSTR lpszCmdLine, int nCmdShow)
{
	return DialogBox(hInstance, MAKEINTRESOURCE(IDD_DIALOG1), NULL, (DLGPROC)DlgProc);
}

void INITBAR() // иницилизация 
{
	hBar = GetDlgItem(hWnd, IDC_BAR);
	SendMessage(hBar, PBM_SETRANGE, NULL, MAKELPARAM(NULL, 1));
	SendMessage(hBar, PBM_SETSTEP, 1, NULL);
	SendMessage(hBar, PBM_SETPOS, NULL, NULL);
	SendMessage(hBar, PBM_SETBKCOLOR, NULL, LPARAM(RGB(NULL, NULL, NULL)));
	SendMessage(hBar, PBM_SETBARCOLOR, NULL, LPARAM(RGB(NULL, NULL, 255)));
}

void timerBar() // работа со временем
{
	SetTimer(hwnd, 1, 1000, NULL);
	SendMessage(hBar, PBM_STEPIT, NULL, NULL);
}


BOOL CALLBACK DlgProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_CLOSE:
		EndDialog(hWnd, NULL);
		return(TRUE);
	case WM_INITDIALOG:
		hB = GetDlgItem(hWnd, IDC_BUTTON1);
		hName = GetDlgItem(hWnd, IDC_NAME);
		hDate = GetDlgItem(hWnd, IDC_DATE);
		SendDlgItemMessage(hWnd, IDC_RADIO1, BM_SETCHECK, WPARAM(BST_UNCHECKED), NULL);
		SendDlgItemMessage(hWnd, IDC_RADIO2, BM_SETCHECK, WPARAM(BST_UNCHECKED), NULL);
		SendDlgItemMessage(hWnd, IDC_RADIO3, BM_SETCHECK, WPARAM(BST_UNCHECKED), NULL);
		SendDlgItemMessage(hWnd, IDC_RADIO4, BM_SETCHECK, WPARAM(BST_UNCHECKED), NULL);
		SendDlgItemMessage(hWnd, IDC_RADIO5, BM_SETCHECK, WPARAM(BST_UNCHECKED), NULL);
		SendDlgItemMessage(hWnd, IDC_RADIO6, BM_SETCHECK, WPARAM(BST_UNCHECKED), NULL);
		SendDlgItemMessage(hWnd, IDC_CHECK1, BM_SETCHECK, WPARAM(BST_UNCHECKED), NULL);
		SendDlgItemMessage(hWnd, IDC_CHECK2, BM_SETCHECK, WPARAM(BST_UNCHECKED), NULL);
		return(TRUE);
	case WM_COMMAND:
		if (LOWORD(wParam) == IDC_RADIO1)
		{
			SendDlgItemMessage(hWnd, IDC_RADIO1, BM_SETCHECK, WPARAM(BST_CHECKED), NULL);
			correctAnswer++;
		}
		else if (LOWORD(wParam) == IDC_RADIO2)
		{
			SendDlgItemMessage(hWnd, IDC_RADIO2, BM_SETCHECK, WPARAM(BST_CHECKED), NULL);
			correctAnswer++;
		}
		else if (LOWORD(wParam) == IDC_RADIO3)
		{
			SendDlgItemMessage(hWnd, IDC_RADIO3, BM_SETCHECK, WPARAM(BST_CHECKED), NULL);
			correctAnswer++;
		}
		else if (LOWORD(wParam) == IDC_RADIO4)
		{
			SendDlgItemMessage(hWnd, IDC_RADIO4, BM_SETCHECK, WPARAM(BST_CHECKED), NULL);
			correctAnswer++;
		}
		else if (LOWORD(wParam) == IDC_RADIO5)
		{
			SendDlgItemMessage(hWnd, IDC_RADIO5, BM_SETCHECK, WPARAM(BST_CHECKED), NULL);
			correctAnswer++;
		}
		else if (LOWORD(wParam) == IDC_RADIO6)
		{
			SendDlgItemMessage(hWnd, IDC_RADIO6, BM_SETCHECK, WPARAM(BST_CHECKED), NULL);
			correctAnswer++;
		}
		else if (LOWORD(wParam) == IDC_NAME) // ввод имени
		{
			while (strlen(name) !> NULL)
			{
				GetWindowText(hName, name, 20);
			}
		}
		else if (LOWORD(wParam) == IDC_DATE) // ввод текущей даты
		{
			while (strlen(date) !> NULL)
			{
				GetWindowText(hDate, date, 20);
			}
		}
		else if (LOWORD(wParam) == IDC_CHECK1)
		{
			SendDlgItemMessage(hWnd, IDC_CHECK1, BM_SETCHECK, WPARAM(BST_CHECKED), NULL);
			correctAnswer++;
		}
		else if (LOWORD(wParam) == IDC_CHECK2)
		{
			SendDlgItemMessage(hWnd, IDC_CHECK2, BM_SETCHECK, WPARAM(BST_CHECKED), NULL);
			correctAnswer++;
		}
		else if (LOWORD(wParam) == IDC_CHECK3 || LOWORD(wParam) == IDC_CHECK4)
		{
			correctAnswer--;
		}
		else
		{
			return(TRUE);
		}
		// - - -
		if (LOWORD(wParam) == IDC_BUTTON1)
		{
			INITBAR();
			timerBar();
			correctAnswer = (double(correctAnswer) / maxAnswer) * 100;
			wsprintf(str, TEXT("%d %hs"), correctAnswer, percent);
			MessageBox(hWnd, str, TEXT("Box"), MB_OK);
			EndDialog(hWnd, NULL);
			return(TRUE);
		}
		else
		{
			return(TRUE);
		}
		return(TRUE);
	}
	return(FALSE);
}

















