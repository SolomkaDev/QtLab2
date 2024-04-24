#pragma once
#include <QDate>
#include <QTextEdit>
#include <QVariant>
#include <QComboBox>
class Info_Storage
{
	//Info_Storage();
	private:
		QString modul;
		QVariant category_value;
		QVariant producer_value;
		double matrix_px;
		QString dimension;
		int weight;
		int price;
		QDate date_release;
		bool IsDigital;
		bool LensOption;
	//Info_Storage::~Info_Storage();
	public:
		Info_Storage();
		Info_Storage(QString modul, QVariant category_value, QVariant producer_value, double matrix_px, QString dimension, int weight, int price, QDate date_release, bool IsDigital, bool LensOption);

		
	
};

