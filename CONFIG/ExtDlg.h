#include "compat.h"
#include "decomp.h"
#include "res/resource.h"

#include <QDialog>
#include <QFileDialog>

namespace Ui
{
class ExtDialog;
}

class CExtDialog : public QDialog {
	Q_OBJECT

public:
	CExtDialog();

private:
	Ui::ExtDialog* m_ui;

	void GetExtensions();

private slots:
		//void accept() override;
		//void reject() override;
};
