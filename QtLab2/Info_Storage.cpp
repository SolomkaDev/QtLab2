#include "Info_Storage.h"
#include <QtWidgets/QApplication>

Info_Storage::Info_Storage()
{
	modul = "Modul name";
	category_value = 0;
	producer_value = 0;
	matrix_px = 20;
	dimension = "SS-VV-TT";
	weight = 30;
	price = 50000;
	date_release = QDate::currentDate();
	IsDigital = true;
	LensOption = false;
}

Info_Storage::Info_Storage(QString modul, QVariant category_v, QVariant producer_v, double px, QString dimen, int wgt, int price, QDate date, bool IsD, bool LOption) {
	this->modul = modul;
	category_value = category_v;
	producer_value = producer_v;
	matrix_px = px;
	dimension = dimen;
	weight = wgt;
	price = price;
	date_release = date;
	IsDigital = IsD;
	LensOption = LOption;

}