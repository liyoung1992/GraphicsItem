#include "widget.h"
#include "ui_widget.h"

// #include "QGraphicsSegment.h"
// #include "QGraphicsCircleItem.h"
// #include "QGraphicsPartitionItem.h"


Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    myscene =  new QGraphicsScene(0,0,255,255);
    ui->graphicsView->setScene(myscene);
    ui->graphicsView->setSceneRect(0,0,255,255);


    //创建一个640x480的图像用于测试
    //CurrentFrame cf;
    curFrame = myscene->addPixmap(*cf.mImage);
    int VideoWidth = cf.width;
    int VideoHeight = cf.height;

    //根据视频大小，设置场景区域
    myscene->setSceneRect(0,0,VideoWidth,VideoHeight);

    //根据视频显示区域的大小，缩放视口的大小和位置
    //设置到视频显示区域
    ui->graphicsView->setParent(ui->label_3);
    //获取视频显示区域的大小
    int height = ui->label_3->height();
    int width = ui->label_3->width();
    qDebug("%d %d",height,width);
    //调整为合适的大小,放置到正中央
    int vHeight = height-4;//边框设置了1个像素，为了显示区别，还空了1个像素，因此-4
    int vWidth = vHeight*4/3;
    int vTop = 2;
    int vLeft = (width-vWidth)/2;
    ui->graphicsView->setGeometry(vLeft,vTop,vWidth,vHeight);
    ui->graphicsView->setSceneRect(0,0,640,480);
    //根据视频大小，进行缩放映射
    ui->graphicsView->resetTransform();
    float s = (float)(vWidth-2)/(float)VideoWidth;  //默认具有1个像素边框,因此-2
    ui->graphicsView->scale(s,s);
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);


    ui->label_5->setText(QString("100"));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_Marker_clicked()
{
     ui->graphicsView->setCurrentMode(GraphicsView::ITEM_MARKER);
}

void Widget::on_SelectItem_clicked()
{
      ui->graphicsView->setCurrentMode(GraphicsView::ITEM_NONE);
}

void Widget::on_DrawLine_clicked()
{
     ui->graphicsView->setCurrentMode(GraphicsView::ITEM_DRAWLINE);
}

void Widget::on_Pencil_clicked()
{
     ui->graphicsView->setCurrentMode(GraphicsView::ITEM_PENCIL);
}

void Widget::on_Text_clicked()
{
     ui->graphicsView->setCurrentMode(GraphicsView::ITEM_TEXT);
}

void Widget::on_Image_clicked()
{
     ui->graphicsView->setCurrentMode(GraphicsView::ITEM_IMAGE);
}

void Widget::on_Curve_clicked()
{
     ui->graphicsView->setCurrentMode(GraphicsView::ITEM_CURVE);
}

void Widget::on_DrawRect_clicked()
{
     ui->graphicsView->setCurrentMode(GraphicsView::ITEM_DRAWRECT);
}

void Widget::on_Ellipse_clicked()
{
     ui->graphicsView->setCurrentMode(GraphicsView::ITEM_CIRCLE);
}

void Widget::on_Time_clicked()
{
     ui->graphicsView->setCurrentMode(GraphicsView::ITEM_TIME);
}

void Widget::on_Distance_clicked()
{
     ui->graphicsView->setCurrentMode(GraphicsView::ITEM_SCALE);
}

void Widget::on_InnerDegree_clicked()
{
    ui->graphicsView->setCurrentMode(GraphicsView::ITEM_INNERDEGREE);
}

void Widget::on_OutterDegree_clicked()
{
    ui->graphicsView->setCurrentMode(GraphicsView::ITEM_OUTTERDEGREE);
}

void Widget::on_CloneRect_clicked()
{
    ui->graphicsView->setCurrentMode(GraphicsView::ITEM_CLONERECT);
}


/*
void Widget::on_Horizontal_clicked()
{
    ui->graphicsView->setCurrentMode(GraphicsView::ITEM_HORIZONTAL);
}

void Widget::on_Vertical_clicked()
{
    ui->graphicsView->setCurrentMode(GraphicsView::ITEM_VERTICAL);
}
*/
void Widget::on_MakerPen_clicked()
{
    ui->graphicsView->setCurrentMode(GraphicsView::ITEM_MARKERPEN);
}

void Widget::on_Color_clicked()//color
{
    const QColor color = QColorDialog::getColor(Qt::green, this, "Select Color");

    if (color.isValid()) {
        ui->graphicsView->setSelectedItemPenColor(color);
    }
}

void Widget::on_font_clicked()
{
    bool ok;
    QFont font = QFontDialog::getFont(&ok, this);
    if (ok) {
        qDebug()<<"font:"<<font;
        ui->graphicsView->setSelectedItemFont(font);
    }
}
void Widget::on_opacity_valueChanged(int value)
{
    ui->graphicsView->setSelectedItemOpacity(value);
    ui->label_5->setText(QString::number(value));
}

void Widget::on_lineStyle_currentIndexChanged(const QString &arg)
{
    if (arg == QString("直线"))
    {
        ui->graphicsView->setSelectedItemLineStyle(ToolAtrribute::LINE);
    }
    else if (arg == QString("左箭头"))
    {
        ui->graphicsView->setSelectedItemLineStyle(ToolAtrribute::LEFT_ARROW);
    }else if (arg == QString("右箭头"))
    {
        ui->graphicsView->setSelectedItemLineStyle(ToolAtrribute::RIGHT_ARROW);
    }else if (arg == QString("双向箭头"))
    {
        ui->graphicsView->setSelectedItemLineStyle(ToolAtrribute::BOTH_ARROW);
    }
}

void Widget::on_LineWidth_currentIndexChanged(int index)
{
    ui->graphicsView->setSelectedItemWidth(index);
}

void Widget::on_brushColor_clicked()
{
    const QColor color = QColorDialog::getColor(Qt::green, this, "Select Color");

    if (color.isValid()) {
        qDebug()<<"color:"<<color;
        ui->graphicsView->setSelectedItemBrushColor(color);
    }

}

void Widget::on_copy_clicked()
{
    ui->graphicsView->Copy();
}

void Widget::on_setOrder_clicked()
{
    ui->graphicsView->setSelectedItemZOrder();
}

void Widget::on_SetAsScale_clicked()
{
    try{
        ui->graphicsView->setScale();
    }
    catch(...)
    {
        qDebug()<<"set scale failed.";
    }
}

void Widget::on_delete_2_clicked()
{
    ui->graphicsView->deleteAllSelected();
}

void Widget::on_paste_clicked()
{
    ui->graphicsView->Paste();
}
//json输入
void Widget::on_save_clicked()
{
    ui->graphicsView->saveItems();
}

//json解析
void Widget::on_load_clicked()
{
    ui->graphicsView->loadItems();
}

void Widget::on_cut_clicked()
{
    ui->graphicsView->Cut();
}



void Widget::flipImage()
{
    bool vflip = ui->VFlip->isChecked();
    bool hflip = ui->HFlip->isChecked();
    QPixmap temp = cf.mImage->copy();
    QPixmap img = QPixmap::fromImage(temp.toImage().mirrored(hflip,vflip));
    curFrame->setPixmap(img);
}

void Widget::on_Zoom_clicked()
{
    ui->graphicsView->setCurrentMode(GraphicsView::GLOBAL_ZOOM);
}

void Widget::on_Move_clicked()
{
    ui->graphicsView->setCurrentMode(GraphicsView::GLOBAL_MOVE);
}

void Widget::on_HFlip_stateChanged(int )
{
    flipImage();
    ui->graphicsView->FlipAllItems(true,false);
}

void Widget::on_VFlip_stateChanged(int )
{
    flipImage();
    ui->graphicsView->FlipAllItems(false,true);
}



