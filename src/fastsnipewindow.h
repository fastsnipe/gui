#ifndef FASTSNIPEWINDOW_H
#define FASTSNIPEWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE

namespace Ui {
	class FastSnipeWindow;
}

QT_END_NAMESPACE

class FastSnipeWindow : public QMainWindow {
	Q_OBJECT

	public:
		FastSnipeWindow(QWidget* parent = nullptr);
		~FastSnipeWindow();
		void set_status_of_stage2(bool);
		void load_settings_from_disk();
	private slots:
		void btnlogin_clicked();
		void btnsave_clicked();
		void sldthreads_valuechanged(int);
	private:
		Ui::FastSnipeWindow* ui;
};
#endif // FASTSNIPEWINDOW_H
