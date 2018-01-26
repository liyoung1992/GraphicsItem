#ifndef GRAPHICSVIEW_H
#define GRAPHICSVIEW_H

#include <QGraphicsView>
#include <QGraphicsItem>
#include <QPair>
#include <QUuid>
#include <QFileDialog>
//#include "QGraphicsPartitionItem.h"
#include "ToolAttribute.h"
#include "items_export.h"

typedef std::map<QUuid, QGraphicsItem*> ITEMS;
typedef ITEMS::iterator ITEMS_ITERATOR;
class ITEMS_EXPORT GraphicsView : public QGraphicsView {
public:
    enum Mode//设置当前所有模式
    {
        ITEM_NONE,       //默认空模式
        ITEM_MARKERPEN,     //标记笔
        ITEM_PENCIL,     //铅笔
        ITEM_TEXT,       //文本
        ITEM_IMAGE,      //图像
        ITEM_MARKER, //十字标记
        ITEM_DRAWLINE,   //绘制直线模式
        ITEM_CURVE,      //曲线
        ITEM_DRAWRECT,  //矩形/正方形
        ITEM_CIRCLE,    //椭圆形
        ITEM_TIME,       //时间
        ITEM_SCALE,   //距离
        ITEM_INNERDEGREE,//内角角度
        ITEM_OUTTERDEGREE,//外角角度
        ITEM_CLONERECT,  //复制矩形
        ITEM_HORIZONTAL, //水平线
        ITEM_VERTICAL,    //垂直线

        GLOBAL_MOVE,     //全局移动模式
        GLOBAL_ZOOM,    //全局缩放模式
        GLOBAL_HFLIP,    //水平翻转
        GLOBAL_VFLIP     //垂直翻转
    };
public:
    //定义了粘贴板
    QVector<QList<QGraphicsItem *> > clipBoard;
    //当前正在绘制的对象
    QGraphicsItem* mCurEditItem;
    //当前模式
    Mode mCurMode;
    //容器，存放所有的Item
    std::map<QUuid, QGraphicsItem*> allItems;
    QList<QGraphicsItem*> Allitems() {
        QList<QGraphicsItem*> result;
        for (std::map<QUuid, QGraphicsItem*>::iterator iter = allItems.begin();
            iter != allItems.end(); iter++) {
            result.push_back(iter->second);
        }
        return result;
    }
    //当前时间戳，其决定了所有item的状态
    qint64 curTime;

    //默认构造函数
    GraphicsView(QWidget * parent = 0);
    //设置当前的模式，决定了如何响应鼠标键盘操作
    void setCurrentMode(Mode mode);
    //获取当前的模式
    Mode getCurrentMode();
    //设置view的当前属性，同时更新所有item
    void setCurTime(qint64 ct) { curTime = ct; setAllItemsCurrentTime(ct); }

    //当观察矩形移动时，更新矩形的位置在视频区域
    void updateTranslateRect();
    //当缩放观察矩形时，更新矩形的位置在视频区域
    void updateTranslateScaleRect();
public:
    //获取所有的选中的item
    QList<QGraphicsItem *> getSelectedItem() const
    {
        return this->scene()->selectedItems();
    }
    //更行所有item的当前时间
    void setAllItemsCurrentTime(qint64 time);
    //显示所有item
    void showAllItems();
    //隐藏所有item
    void hideAllItems();
    //h为true表示水平翻转，v为true表示垂直翻转
    void FlipAllItems(bool h, bool v);

    //剪切板是否为空. 返回值  1：表示空;0：表示非空;
    bool ClipBoardEmpty() { return clipBoard.empty(); }
    //粘贴
    int Paste();
    //将当前场景中选中的对象copy至剪贴板
    int Copy();
    //读取当前剪贴板的对象
    QList<QGraphicsItem*> GetCopy();
    //清空剪切板
    void ClearClipBoard() { clipBoard.clear(); }
    //删除所有选中的Item
    int deleteAllSelected();
    //删除所有的item
    int deleteAll();
    //剪切
    int Cut();
    //撤销
    void Redo() {};
    //重做
    void Undo() {}

    //选中item的z值+1，
    int setSelectedItemZOrder();
    //设置选中item的画笔
    int setSelectedItemPenColor(QColor color);
    //设置选中item的画刷
    int setSelectedItemBrushColor(QColor color);
    //设置选中item的字体
    int setSelectedItemFont(QFont font);
    //设置选中item的线宽
    int setSelectedItemWidth(const int width);
    //设置选中item的箭头类型
    int setSelectedItemLineStyle(ToolAtrribute::ArrowType style);
    //设置选中item的透明度
    int setSelectedItemOpacity(int value);
    void setToolAttribute(ToolAtrribute*);
    //将比例尺设为参考操作
    void setScale();
    //设置图片工具所需的图片
    void setItemImage(QString);

    //保存
    int saveItems();
    //载入
    int loadItems();


    // 重设定时器处理函数
    void TimerReset();
    // 开始计时处理函数
    void StartTimer();
    // 结束定时处理函数
    void StopTimer();

   //点击放大与缩小
    void ZoomParam(bool);


private:
    //true表示水平翻转
    bool mHFlip;
    //true表示垂直翻转
    bool mVFlip;
    //开始拖放时的全局坐标
    QPointF mStartScenePoint; 
    //开始拖放时观察矩形的坐标
    QRectF mStartRect;      


    ToolAtrribute* toolAttribute;
    QGraphicsItem* parent_rect_;

    //图片工具所指图片的路径
    QString imgPath;
protected:
    void mousePressEvent(QMouseEvent* event) override;
    void mouseMoveEvent(QMouseEvent* event) override;
    void mouseDoubleClickEvent(QMouseEvent* event) override;
    void mouseReleaseEvent(QMouseEvent* event) override;
    void wheelEvent(QWheelEvent* event) override;
    void dragEnterEvent(QDragEnterEvent* event) override;
    void dragMoveEvent(QDragMoveEvent* event) override;
    void keyPressEvent(QKeyEvent* event) override;
    void OnMouseMove(QMouseEvent* event);
};

#endif // GRAPHICSVIEW_H
