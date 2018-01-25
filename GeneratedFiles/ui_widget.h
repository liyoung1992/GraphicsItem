/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>
#include <graphicsview.h>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    GraphicsView *graphicsView;
    QGroupBox *groupBox;
    QRadioButton *Marker;
    QRadioButton *Pencil;
    QRadioButton *Text;
    QRadioButton *Image;
    QRadioButton *MakerPen;
    QRadioButton *DrawLine;
    QRadioButton *Curve;
    QRadioButton *DrawRect;
    QRadioButton *Ellipse;
    QRadioButton *Time;
    QRadioButton *Distance;
    QRadioButton *InnerDegree;
    QRadioButton *OutterDegree;
    QRadioButton *SelectItem;
    QRadioButton *Zoom;
    QRadioButton *Move;
    QToolButton *toolButton;
    QLabel *label;
    QLabel *label_3;
    QPushButton *Color;
    QPushButton *font;
    QComboBox *LineWidth;
    QSlider *opacity;
    QLabel *label_2;
    QComboBox *lineStyle;
    QLabel *label_4;
    QLabel *label_5;
    QPushButton *brushColor;
    QCheckBox *Horizontal;
    QCheckBox *Vertical;
    QCheckBox *HFlip;
    QCheckBox *VFlip;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(780, 469);
        graphicsView = new GraphicsView(Widget);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setGeometry(QRect(130, 20, 261, 361));
        groupBox = new QGroupBox(Widget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(10, 10, 101, 361));
        Marker = new QRadioButton(groupBox);
        Marker->setObjectName(QStringLiteral("Marker"));
        Marker->setGeometry(QRect(10, 20, 89, 16));
        Pencil = new QRadioButton(groupBox);
        Pencil->setObjectName(QStringLiteral("Pencil"));
        Pencil->setGeometry(QRect(10, 40, 89, 16));
        Text = new QRadioButton(groupBox);
        Text->setObjectName(QStringLiteral("Text"));
        Text->setGeometry(QRect(10, 60, 89, 16));
        Image = new QRadioButton(groupBox);
        Image->setObjectName(QStringLiteral("Image"));
        Image->setGeometry(QRect(10, 80, 89, 16));
        MakerPen = new QRadioButton(groupBox);
        MakerPen->setObjectName(QStringLiteral("MakerPen"));
        MakerPen->setGeometry(QRect(10, 100, 89, 16));
        DrawLine = new QRadioButton(groupBox);
        DrawLine->setObjectName(QStringLiteral("DrawLine"));
        DrawLine->setGeometry(QRect(10, 120, 89, 16));
        Curve = new QRadioButton(groupBox);
        Curve->setObjectName(QStringLiteral("Curve"));
        Curve->setGeometry(QRect(10, 140, 89, 16));
        DrawRect = new QRadioButton(groupBox);
        DrawRect->setObjectName(QStringLiteral("DrawRect"));
        DrawRect->setGeometry(QRect(10, 160, 89, 16));
        Ellipse = new QRadioButton(groupBox);
        Ellipse->setObjectName(QStringLiteral("Ellipse"));
        Ellipse->setGeometry(QRect(10, 180, 89, 16));
        Time = new QRadioButton(groupBox);
        Time->setObjectName(QStringLiteral("Time"));
        Time->setGeometry(QRect(10, 200, 89, 16));
        Distance = new QRadioButton(groupBox);
        Distance->setObjectName(QStringLiteral("Distance"));
        Distance->setGeometry(QRect(10, 220, 89, 16));
        InnerDegree = new QRadioButton(groupBox);
        InnerDegree->setObjectName(QStringLiteral("InnerDegree"));
        InnerDegree->setGeometry(QRect(10, 240, 89, 16));
        OutterDegree = new QRadioButton(groupBox);
        OutterDegree->setObjectName(QStringLiteral("OutterDegree"));
        OutterDegree->setGeometry(QRect(10, 260, 89, 16));
        SelectItem = new QRadioButton(groupBox);
        SelectItem->setObjectName(QStringLiteral("SelectItem"));
        SelectItem->setGeometry(QRect(10, 320, 89, 16));
        SelectItem->setChecked(true);
        Zoom = new QRadioButton(groupBox);
        Zoom->setObjectName(QStringLiteral("Zoom"));
        Zoom->setGeometry(QRect(10, 280, 61, 16));
        Move = new QRadioButton(groupBox);
        Move->setObjectName(QStringLiteral("Move"));
        Move->setGeometry(QRect(10, 300, 51, 16));
        toolButton = new QToolButton(groupBox);
        toolButton->setObjectName(QStringLiteral("toolButton"));
        toolButton->setGeometry(QRect(250, 140, 37, 18));
        label = new QLabel(Widget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(500, 420, 61, 16));
        label_3 = new QLabel(Widget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(130, 20, 640, 360));
        label_3->setFrameShape(QFrame::Panel);
        Color = new QPushButton(Widget);
        Color->setObjectName(QStringLiteral("Color"));
        Color->setGeometry(QRect(410, 440, 51, 23));
        font = new QPushButton(Widget);
        font->setObjectName(QStringLiteral("font"));
        font->setGeometry(QRect(460, 440, 41, 23));
        LineWidth = new QComboBox(Widget);
        LineWidth->setObjectName(QStringLiteral("LineWidth"));
        LineWidth->setGeometry(QRect(500, 440, 69, 22));
        LineWidth->setMinimumSize(QSize(69, 22));
        LineWidth->setMaximumSize(QSize(69, 22));
        LineWidth->setMaxVisibleItems(30);
        opacity = new QSlider(Widget);
        opacity->setObjectName(QStringLiteral("opacity"));
        opacity->setGeometry(QRect(580, 440, 160, 19));
        opacity->setMinimumSize(QSize(160, 19));
        opacity->setMinimum(1);
        opacity->setMaximum(100);
        opacity->setPageStep(2);
        opacity->setValue(100);
        opacity->setOrientation(Qt::Horizontal);
        opacity->setTickPosition(QSlider::TicksBelow);
        label_2 = new QLabel(Widget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(580, 420, 61, 16));
        lineStyle = new QComboBox(Widget);
        lineStyle->setObjectName(QStringLiteral("lineStyle"));
        lineStyle->setGeometry(QRect(298, 440, 61, 22));
        label_4 = new QLabel(Widget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(300, 420, 61, 16));
        label_5 = new QLabel(Widget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(630, 420, 54, 12));
        brushColor = new QPushButton(Widget);
        brushColor->setObjectName(QStringLiteral("brushColor"));
        brushColor->setGeometry(QRect(360, 440, 51, 23));
        Horizontal = new QCheckBox(Widget);
        Horizontal->setObjectName(QStringLiteral("Horizontal"));
        Horizontal->setGeometry(QRect(100, 390, 81, 16));
        Vertical = new QCheckBox(Widget);
        Vertical->setObjectName(QStringLiteral("Vertical"));
        Vertical->setGeometry(QRect(100, 420, 71, 16));
        HFlip = new QCheckBox(Widget);
        HFlip->setObjectName(QStringLiteral("HFlip"));
        HFlip->setGeometry(QRect(200, 390, 71, 16));
        VFlip = new QCheckBox(Widget);
        VFlip->setObjectName(QStringLiteral("VFlip"));
        VFlip->setGeometry(QRect(200, 420, 71, 16));

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", 0));
        groupBox->setTitle(QApplication::translate("Widget", "GroupBox", 0));
        Marker->setText(QApplication::translate("Widget", "Marker", 0));
        Pencil->setText(QApplication::translate("Widget", "Pencil", 0));
        Text->setText(QApplication::translate("Widget", "Text", 0));
        Image->setText(QApplication::translate("Widget", "Image", 0));
        MakerPen->setText(QApplication::translate("Widget", "MarkerPen", 0));
        DrawLine->setText(QApplication::translate("Widget", "DrawLine", 0));
        Curve->setText(QApplication::translate("Widget", "Curve", 0));
        DrawRect->setText(QApplication::translate("Widget", "DrawRect", 0));
        Ellipse->setText(QApplication::translate("Widget", "Ellipse", 0));
        Time->setText(QApplication::translate("Widget", "Time", 0));
        Distance->setText(QApplication::translate("Widget", "Distance", 0));
        InnerDegree->setText(QApplication::translate("Widget", "InnerDegree", 0));
        OutterDegree->setText(QApplication::translate("Widget", "OutterDegree", 0));
        SelectItem->setText(QApplication::translate("Widget", "\351\200\211\346\213\251", 0));
        Zoom->setText(QApplication::translate("Widget", "Zoom", 0));
        Move->setText(QApplication::translate("Widget", "Move", 0));
        toolButton->setText(QApplication::translate("Widget", "...", 0));
        label->setText(QApplication::translate("Widget", "\347\272\277\345\256\275\346\265\213\350\257\225\357\274\232", 0));
        label_3->setText(QString());
        Color->setText(QApplication::translate("Widget", "\351\242\234\350\211\262", 0));
        font->setText(QApplication::translate("Widget", "\345\255\227\344\275\223", 0));
        LineWidth->clear();
        LineWidth->insertItems(0, QStringList()
         << QApplication::translate("Widget", "1", 0)
         << QApplication::translate("Widget", "2", 0)
         << QApplication::translate("Widget", "3", 0)
         << QApplication::translate("Widget", "4", 0)
         << QApplication::translate("Widget", "5", 0)
         << QApplication::translate("Widget", "6", 0)
         << QApplication::translate("Widget", "7", 0)
         << QApplication::translate("Widget", "8", 0)
         << QApplication::translate("Widget", "9", 0)
         << QApplication::translate("Widget", "10", 0)
         << QApplication::translate("Widget", "11", 0)
         << QApplication::translate("Widget", "12", 0)
         << QApplication::translate("Widget", "13", 0)
         << QApplication::translate("Widget", "14", 0)
         << QApplication::translate("Widget", "15", 0)
         << QApplication::translate("Widget", "16", 0)
         << QApplication::translate("Widget", "17", 0)
         << QApplication::translate("Widget", "18", 0)
         << QApplication::translate("Widget", "19", 0)
         << QApplication::translate("Widget", "20", 0)
         << QApplication::translate("Widget", "21", 0)
         << QApplication::translate("Widget", "22", 0)
         << QApplication::translate("Widget", "23", 0)
         << QApplication::translate("Widget", "24", 0)
         << QApplication::translate("Widget", "25", 0)
         << QApplication::translate("Widget", "\346\226\260\345\273\272\351\241\271\347\233\256", 0)
        );
        label_2->setText(QApplication::translate("Widget", "\351\200\217\346\230\216\345\272\246:", 0));
        lineStyle->clear();
        lineStyle->insertItems(0, QStringList()
         << QApplication::translate("Widget", "\347\233\264\347\272\277", 0)
         << QApplication::translate("Widget", "\345\267\246\347\256\255\345\244\264", 0)
         << QApplication::translate("Widget", "\345\217\263\347\256\255\345\244\264", 0)
         << QApplication::translate("Widget", "\345\217\214\345\220\221\347\256\255\345\244\264", 0)
        );
        label_4->setText(QApplication::translate("Widget", "\347\272\277\345\275\242\346\265\213\350\257\225", 0));
        label_5->setText(QApplication::translate("Widget", "100", 0));
        brushColor->setText(QApplication::translate("Widget", "\345\241\253\345\205\205", 0));
        Horizontal->setText(QApplication::translate("Widget", "Horizontal", 0));
        Vertical->setText(QApplication::translate("Widget", "Vertical", 0));
        HFlip->setText(QApplication::translate("Widget", "HFlip", 0));
        VFlip->setText(QApplication::translate("Widget", "VFlip", 0));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
