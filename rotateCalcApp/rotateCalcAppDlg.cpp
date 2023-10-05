
// rotateCalcAppDlg.cpp: файл реализации
//

#include "pch.h"
#include "framework.h"
#include "rotateCalcApp.h"
#include "rotateCalcAppDlg.h"
#include "afxdialogex.h"

#include <cmath>

#ifndef M_PI
#define M_PI  3.14159265358979323846 
#endif

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Диалоговое окно CAboutDlg используется для описания сведений о приложении

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV

// Реализация
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// Диалоговое окно CrotateCalcAppDlg



CrotateCalcAppDlg::CrotateCalcAppDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_ROTATECALCAPP_DIALOG, pParent)
	, invertCoords(false)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CrotateCalcAppDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CrotateCalcAppDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_CHECK1, &CrotateCalcAppDlg::OnBnClickedCheck1)
	ON_BN_CLICKED(IDC_BUTTON1, &CrotateCalcAppDlg::OnBnClickedButton1)
	ON_EN_CHANGE(IDC_EDIT_X1, &CrotateCalcAppDlg::OnLetterEntered_X1)
	ON_EN_CHANGE(IDC_EDIT_Y1, &CrotateCalcAppDlg::onLetterEntered_Y1)
	ON_EN_CHANGE(IDC_EDIT_XX1, &CrotateCalcAppDlg::onLetterEntered_XX1)
	ON_EN_CHANGE(IDC_EDIT_YY1, &CrotateCalcAppDlg::onLetterEntered_YY1)
	ON_EN_CHANGE(IDC_EDIT_X2, &CrotateCalcAppDlg::onLetterEntered_X2)
	ON_EN_CHANGE(IDC_EDIT_Y2, &CrotateCalcAppDlg::onLetterEntered_Y2)
	ON_EN_CHANGE(IDC_EDIT_XX2, &CrotateCalcAppDlg::onLetterEntered_XX2)
	ON_EN_CHANGE(IDC_EDIT_YY2, &CrotateCalcAppDlg::onLetterEntered_YY2)
END_MESSAGE_MAP()


// Обработчики сообщений CrotateCalcAppDlg

BOOL CrotateCalcAppDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Добавление пункта "О программе..." в системное меню.

	// IDM_ABOUTBOX должен быть в пределах системной команды.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Задает значок для этого диалогового окна.  Среда делает это автоматически,
	//  если главное окно приложения не является диалоговым
	SetIcon(m_hIcon, TRUE);			// Крупный значок
	SetIcon(m_hIcon, FALSE);		// Мелкий значок

	// TODO: добавьте дополнительную инициализацию

	return TRUE;  // возврат значения TRUE, если фокус не передан элементу управления
}

void CrotateCalcAppDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// При добавлении кнопки свертывания в диалоговое окно нужно воспользоваться приведенным ниже кодом,
//  чтобы нарисовать значок.  Для приложений MFC, использующих модель документов или представлений,
//  это автоматически выполняется рабочей областью.

void CrotateCalcAppDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // контекст устройства для рисования

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Выравнивание значка по центру клиентского прямоугольника
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Нарисуйте значок
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// Система вызывает эту функцию для получения отображения курсора при перемещении
//  свернутого окна.
HCURSOR CrotateCalcAppDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CrotateCalcAppDlg::OnBnClickedCheck1()
{
	CButton* m_ctlCheck = (CButton*)GetDlgItem(IDC_CHECK1);
	int ChkBox = m_ctlCheck->GetCheck();

	if (ChkBox == BST_UNCHECKED)
		invertCoords = false;
	else if (ChkBox == BST_CHECKED)
		invertCoords = true;
}

void CrotateCalcAppDlg::OnBnClickedButton1()
{
	double x1, y1, xx1, yy1, x2, y2, xx2, yy2;
	wchar_t* end;
	CString lastValue;

	CEdit* m_Edit = (CEdit*)GetDlgItem(IDC_EDIT_X1);
	m_Edit->GetWindowText(lastValue);
	x1 = wcstod(lastValue.GetBuffer(), &end);

	m_Edit = (CEdit*)GetDlgItem(IDC_EDIT_Y1);
	m_Edit->GetWindowText(lastValue);
	y1 = wcstod(lastValue.GetBuffer(), &end);

	m_Edit = (CEdit*)GetDlgItem(IDC_EDIT_X2);
	m_Edit->GetWindowText(lastValue);
	x2 = wcstod(lastValue.GetBuffer(), &end);

	m_Edit = (CEdit*)GetDlgItem(IDC_EDIT_Y2);
	m_Edit->GetWindowText(lastValue);
	y2 = wcstod(lastValue.GetBuffer(), &end);

	m_Edit = (CEdit*)GetDlgItem(IDC_EDIT_XX1);
	m_Edit->GetWindowText(lastValue);
	xx1 = wcstod(lastValue.GetBuffer(), &end);

	m_Edit = (CEdit*)GetDlgItem(IDC_EDIT_YY1);
	m_Edit->GetWindowText(lastValue);
	yy1 = wcstod(lastValue.GetBuffer(), &end);

	m_Edit = (CEdit*)GetDlgItem(IDC_EDIT_XX2);
	m_Edit->GetWindowText(lastValue);
	xx2 = wcstod(lastValue.GetBuffer(), &end);

	m_Edit = (CEdit*)GetDlgItem(IDC_EDIT_YY2);
	m_Edit->GetWindowText(lastValue);
	yy2 = wcstod(lastValue.GetBuffer(), &end);

	double val;
	if (invertCoords)
		val = calculate(dblPair{ xx1, yy1 }, dblPair{ x1,y1 }, dblPair{ xx2, yy2 }, dblPair{ x2, y2 });
	else
		val =  calculate(dblPair{ x1,y1 }, dblPair{ xx1, yy1 }, dblPair{ x2, y2 }, dblPair{ xx2, yy2 });

	m_Edit = (CEdit*)GetDlgItem(IDC_EDIT_OUT);

	if (std::isnan(val))
	{
		m_Edit->SetWindowText(L"Не удалось вычислить значение");
	}
	else {
		CString line;
		line.Format(L"Команда поворота: G68 X0.0 Y0.0 R %g", val);
		m_Edit->SetWindowText(line);
	}
}

double CrotateCalcAppDlg::calculate(const dblPair &P1, const dblPair& P1_hat, const dblPair& P2, const dblPair& P2_hat )
{
	double X = P2.first - P1.first;
	double Y = P2.second - P1.second;
	double X_hat = P2_hat.first - P1_hat.first;
	double Y_hat = P2_hat.second - P1_hat.second;

	if (fabs(X) < 1e-5 && fabs(Y) < 1e-5)
		return NAN;
	if (fabs(X) < 1e-5)
	{
		if (fabs(Y_hat) > 1e-5) {
			double rv = atan(-X_hat / Y_hat);
			rv *= 180. / M_PI;
			return rv;
		}
		else {
			printf( "case X == 0,  Y <> 0, Y_hat == 0");
			return NAN;
		}
	}
	if (fabs(Y) < 1e-5)
	{
		if (fabs(X_hat) > 1e-5) {
			double rv = atan(Y_hat / X_hat);
			rv *= 180. / M_PI;
			return rv;
		}
		else {
			printf( "case X <> 0,  Y == 0, X_hat == 0");
			return NAN;
		}
	}
	double rv = acos((X * X_hat + Y * Y_hat) / (sqrt(X * X + Y * Y)* sqrt(X_hat * X_hat + Y_hat * Y_hat)));
	rv *= 180. / M_PI;
	return rv;
}

void CrotateCalcAppDlg::commonAnalyzes(int id, CString & lastKnownLine)
{
	CEdit* m_Edit = (CEdit*)GetDlgItem(id);
	CString lastValue;
	m_Edit->GetWindowText(lastValue);
	if (lastValue == "")
	{
		lastKnownLine = lastValue;
		return;
	}
	if (lastValue == lastKnownLine)
	{
		return;
	}
	wchar_t* ptr = lastValue.GetBuffer(lastValue.GetLength());
	wchar_t* end;
	double val =  wcstod(ptr, &end);
	if (end - ptr < lastValue.GetLength()) {
		m_Edit->SetWindowText(lastKnownLine);
		return;
	}
	lastKnownLine = lastValue;
}

void CrotateCalcAppDlg::OnLetterEntered_X1()
{
	commonAnalyzes(IDC_EDIT_X1, x1_line);
	printf("new letter arrived");
	return;
}

void CrotateCalcAppDlg::onLetterEntered_Y1()
{
	commonAnalyzes(IDC_EDIT_Y1, y1_line);
}


void CrotateCalcAppDlg::onLetterEntered_XX1()
{
	commonAnalyzes(IDC_EDIT_XX1, xx1_line);
}


void CrotateCalcAppDlg::onLetterEntered_YY1()
{
	commonAnalyzes(IDC_EDIT_YY1, yy1_line);
}


void CrotateCalcAppDlg::onLetterEntered_X2()
{
	commonAnalyzes(IDC_EDIT_X2, x2_line);
}


void CrotateCalcAppDlg::onLetterEntered_Y2()
{
	commonAnalyzes(IDC_EDIT_Y2, y2_line);
}


void CrotateCalcAppDlg::onLetterEntered_XX2()
{
	commonAnalyzes(IDC_EDIT_XX2, xx2_line);
}


void CrotateCalcAppDlg::onLetterEntered_YY2()
{
	commonAnalyzes(IDC_EDIT_YY2, yy2_line);
}
