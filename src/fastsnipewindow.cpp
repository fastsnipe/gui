#include "fastsnipewindow.h"
#include "uic/ui_fastsnipewindow.h"
#include <QMessageBox>

#include "mojang/mojang.hpp"
#include <fstream>
#include <iostream>
#include <sstream>
FastSnipeWindow::FastSnipeWindow(QWidget* parent)
	: QMainWindow(parent)
	  , ui(new Ui::FastSnipeWindow) {
	ui->setupUi(this);
	connect(ui->btnLogin, SIGNAL(clicked()), this, SLOT(btnlogin_clicked()));
	connect(ui->btnSave, SIGNAL(clicked()), this, SLOT(btnsave_clicked()));
	connect(ui->sldThreads, SIGNAL(valueChanged(int)), this, SLOT(sldthreads_valuechanged(int)));

	set_status_of_stage2(false);
	load_settings_from_disk();
}

FastSnipeWindow::~FastSnipeWindow() {
	delete ui;
}

void FastSnipeWindow::set_status_of_stage2(bool status) {
	ui->lblStage2->setEnabled(status);
	ui->lblStage2R->setEnabled(status);
	ui->lblWantedName->setEnabled(status);
	ui->txtWantedName->setEnabled(status);
	ui->lblThreads->setEnabled(status);
	ui->sldThreads->setEnabled(status);
	ui->btnSave->setEnabled(status);
}

void FastSnipeWindow::sldthreads_valuechanged(int val) {
	ui->lblThreads->setText(QString::fromStdString(std::string("Threads (") + std::to_string(val) + ")"));
}
login_response_t res;
void FastSnipeWindow::load_settings_from_disk() {
	if (!std::filesystem::exists("config.json"))
		return;

	const std::ifstream f("config.json");
	if (f.is_open()) {
		std::stringstream stream;
		stream << f.rdbuf(); //read the file
		const auto str = stream.str();
		const auto j = json::parse(str);
		if (j.contains("auth")) {
			if (j["auth"].contains("email")) ui->txtEmail->setText(QString::fromStdString(j["auth"]["email"].get<std::string>()));
			if (j["auth"].contains("password")) ui->txtPassword->setText(QString::fromStdString(j["auth"]["password"].get<std::string>()));
			//if (j["auth"].contains("uuid")) ui->txtUUID->setText(QString::fromStdString(j["auth"]["uuid"].get<std::string>()));
			if (j["auth"].contains("token")) ui->txtToken->setText(QString::fromStdString(j["auth"]["token"].get<std::string>()));
			if (j["auth"].contains("client_token")) {} // TODO: do something with client_token (in future)
		}
		if (j.contains("wanted")) {
			if (j["wanted"].contains("name")) ui->txtWantedName->setText(QString::fromStdString(j["wanted"]["name"].get<std::string>()));
		}
		if (j.contains("threading")) {
			if (j["threading"].contains("threads")) ui->sldThreads->setValue(j["threading"]["threads"].get<int>());
			if (j["threading"].contains("no_delay")) ui->chkNoDelay->setChecked(j["threading"]["no_delay"].get<bool>());
		}
	}
}

void FastSnipeWindow::btnsave_clicked() {
	// generate json for cfg
	json j = {
		{
			"auth",
			{
				{"email", ui->txtEmail->text().toStdString()},
				{"password", ui->txtPassword->text().toStdString()},
				{"uuid", res.uuid},
				{"token", ui->txtToken->text().toStdString()}
			}
		},
		{
			"wanted",
			{
				{"name", ui->txtWantedName->text().toStdString()}
			}
		},
		{
			"threading",
			{
				{"threads", ui->sldThreads->value()},
				{"no_delay", ui->chkNoDelay->isChecked()}
			}
		}
	};

	// open
	std::ofstream out("config.json");
	out << j.dump();
	out.close();

	// write batch file that runs fastsnipe
	std::ofstream out_bat("run.bat");
	out_bat << "@ECHO OFF\n";
	out_bat << "fastsnipe.exe -c config.json\n";
	out_bat << "pause\n";
	out_bat.close();

	QMessageBox msg_box;
	msg_box.setText("Success! Created your config. Now you can run the batch file created to start fastsnipe.");
	msg_box.setIcon(QMessageBox::Icon::Information);
	msg_box.exec();
}
void FastSnipeWindow::btnlogin_clicked() {
	if (ui->txtToken->text().isEmpty()) {
		res = mojang::login_with_password(this, ui->txtEmail->text().toStdString(), ui->txtPassword->text().toStdString());
	} else { // atempt login with token
		res = mojang::login_with_token(ui->txtToken->text().toStdString());
	}
	if (!res.successful) {
		set_status_of_stage2(false);
		ui->lblStatus->setStyleSheet("QLabel{color: red;}");
		ui->lblStatus->setText("Failed to login");

		QMessageBox msg_box;
		msg_box.setText("Failed to login to Mojang with your provided credentials.");
		msg_box.setInformativeText(QString::fromStdString(mojang::get_last_error()));
		msg_box.setIcon(QMessageBox::Icon::Critical);
		msg_box.exec();
		return;
	}
	ui->txtUsername->setText(QString::fromStdString(res.username));
	ui->txtUUID->setText(QString::fromStdString(res.uuid));
	ui->lblStatus->setStyleSheet("QLabel{color: green;}");
	ui->lblStatus->setText("Success!");
	
	set_status_of_stage2(true);
}