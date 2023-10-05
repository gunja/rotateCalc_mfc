
// rotateCalcAppDlg.h: файл заголовка
//

#pragma once

#include<string>
#include <utility>

using dblPair = std::pair<double, double>;


// Диалоговое окно CrotateCalcAppDlg
class CrotateCalcAppDlg : public CDialogEx
{
// Создание
public:
	CrotateCalcAppDlg(CWnd* pParent = nullptr);	// стандартный конструктор

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ROTATECALCAPP_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// поддержка DDX/DDV


// Реализация
protected:
	HICON m_hIcon;
	bool invertCoords;
	CString x1_line, y1_line, x2_line, y2_line, xx1_line, yy1_line, xx2_line, yy2_line;
	void commonAnalyzes(int, CString&);
	double calculate(const dblPair&, const dblPair& , const dblPair&, const dblPair& );

	// Созданные функции схемы сообщений
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedCheck1();
	afx_msg void OnBnClickedButton1();
	afx_msg void  OnLetterEntered_X1();
	afx_msg void onLetterEntered_Y1();
	afx_msg void onLetterEntered_XX1();
	afx_msg void onLetterEntered_YY1();
	afx_msg void onLetterEntered_X2();
	afx_msg void onLetterEntered_Y2();
	afx_msg void onLetterEntered_XX2();
	afx_msg void onLetterEntered_YY2();
};
