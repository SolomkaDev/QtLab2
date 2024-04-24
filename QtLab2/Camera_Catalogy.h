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
        void slot_save1(); //���������|������������ ������ ������
        void slot_save2(); //���������|������������ ������ ������
        void slot_show1(); //�������� ������ ������ ������
        void slot_show2(); //�������� ������ ������ ������
        void slot_LensOptions(); //������� � ������������ ����� ���������
        void slot_IsDigital(); //������� �������� �� ������ ��������
        void slot_ChooseCategory(); //����� ��������� ������ �� ����������� ������
        void slot_ChooseProducer(); //����� ������������� ������ �� ����������� ������

        
};
