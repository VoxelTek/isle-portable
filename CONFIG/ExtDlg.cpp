#include "ExtDlg.h"

#ifdef MINIWIN
#include "miniwin/windows.h"
#else
#include <windows.h>
#endif

#include "config.h"
#include "res/resource.h"

#include <ui_extdialog.h>

CExtDialog::CExtDialog() : QDialog()
{
	m_ui = new Ui::ExtDialog;
	m_ui->setupUi(this);
	layout()->setSizeConstraint(QLayout::SetFixedSize);

	GetExtensions();
}


void CExtDialog::GetExtensions() {
	QFile file("extensions.json");
	if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;

}
