#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Camera_Catalogy.h"
#include "Info_Storage.h"


class Storage_Camera {
    public:
        QString modul;
        int category_value;
        int producer_value;
        double matrix_px;
        QString dimension;
        int weight;
        int price;
        QDate date_release;
        bool IsDigital;
        bool LensOption;
};

class Camera_Catalogy : public QMainWindow
{
    Q_OBJECT

public:
    Camera_Catalogy(QWidget *parent = Q_NULLPTR);
    Storage_Camera Items[2];

    

private:
    Ui::Camera_CatalogyClass ui;
    private slots:
        void slot_save1(); //Сохранить|Перезаписать первую запись
        void slot_save2(); //Сохранить|Перезаписать вторую запись
        void slot_show1(); //Показать данные первой записи
        void slot_show2(); //Показать данные второй записи
        void slot_LensOptions(); //Чекбокс о возможностях смены объектива
        void slot_IsDigital(); //Чекбокс является ли камера цифровой
        void slot_ChooseCategory(); //Выбор категории камеры из выподающего списка
        void slot_ChooseProducer(); //Выбор производителя камеры из выподающего списка

        
};
