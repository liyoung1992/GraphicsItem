#ifndef WIDGET_H
#define WIDGET_H

//#include "QGraphicsPartitionItem.h"
#include "GraphicsView.h"
#include <QPainter>
#include <QWidget>
#include <QColorDialog>
#include <QFontDialog>
#include <QGraphicsPixmapItem>
namespace Ui {
class Widget;
}

//For test
class CurrentFrame
{
public:
    CurrentFrame()
    {
        width=640;
        height=480;
        mImage = new QPixmap(640,480);
        QPainter painter;
        painter.begin(mImage);
        QPen pen;
        pen.setWidth(1);
        pen.setColor(QColor(255,0,0));
        QBrush brush;
        brush.setColor(QColor(128,128,128));
        painter.setPen(pen);
        painter.setBrush(brush);
        painter.fillRect(QRect(0,0,640,480),QBrush(QColor(255,255,255)));
//        painter.drawRect(QRect(0,0,639,479));
        //painter.fillRect(QRect(100,100,50,50),QBrush(QColor(255,0,0)));
        painter.end();
        mImage->save("bg.bmp");
    }
    ~CurrentFrame()
    {
        delete mImage;
    }

    int width;
    int height;
    QPixmap* mImage;
};

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
protected:
    void flipImage();
private slots:

    void on_Marker_clicked();

    void on_SelectItem_clicked();

    void on_DrawLine_clicked();

    void on_Pencil_clicked();

    void on_Text_clicked();

    void on_Image_clicked();

    void on_Curve_clicked();

    void on_DrawRect_clicked();

    void on_Ellipse_clicked();

    void on_Time_clicked();

    void on_Distance_clicked();

    void on_InnerDegree_clicked();

    void on_OutterDegree_clicked();

    void on_CloneRect_clicked();

    //void on_Horizontal_clicked();

    //void on_Vertical_clicked();

    void on_MakerPen_clicked();

    void on_Color_clicked();

    void on_font_clicked();

    void on_opacity_valueChanged(int value);

    void on_lineStyle_currentIndexChanged(const QString &arg1);

    void on_LineWidth_currentIndexChanged(int index);

    void on_brushColor_clicked();

    void on_delete_2_clicked();

    void on_copy_clicked();

    void on_setOrder_clicked();

    void on_SetAsScale_clicked();

    void on_paste_clicked();

    void on_save_clicked();

    void on_load_clicked();

    void on_cut_clicked();



    void on_Zoom_clicked();

    void on_Move_clicked();

    void on_HFlip_stateChanged(int arg1);

    void on_VFlip_stateChanged(int arg1);



private:
    Ui::Widget *ui;
    CurrentFrame cf;
    QGraphicsPixmapItem * curFrame;
    QGraphicsScene* myscene;
};

#endif // WIDGET_H
