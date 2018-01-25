#ifndef _TOOL_ATTRIBUTE_H
#define _TOOL_ATTRIBUTE_H

#include<QCoreApplication>
#include<QDataStream>
#include<QFile>
#include<QHash>
#include<iostream>
#include<QDebug>
#include <QFont>
#include <QColor>
#include "items_export.h"
//绘制工具使用的属性
class ITEMS_EXPORT ToolAtrribute
{
public:
  enum ArrowType
  {
    LINE,//普通直线
    LEFT_ARROW,//带左箭头直线
    RIGHT_ARROW,//带右箭头直线
    BOTH_ARROW//双向箭头直线
  };
private:
  int width;//线宽
  QColor penColor;//画笔颜色
  QColor brushColor;//填充颜色
  ArrowType arrow;//线条类型
  QFont itemFont;//字体
  float itemOpacity;//取值为0至1，透明度,1表示完全不透明
  bool widthEnable;//线宽是否修改
  bool penEnable;//画笔颜色是否修改
  bool brushEnable;//填充画刷是否可修改
  bool arrowEnable;//箭头是否修改，即是否可以调整线形
  bool fontEnable;//字体是否可以修改
  bool opacityEnable;
public:
  void SetArrow(const ArrowType arrow){
    this->arrow = arrow;
  }
  ArrowType Arrow()const{
    return arrow;
  }

  bool ArrowEnable()const{
    return arrowEnable;
  }
  void SetArrowEnable(const bool b){
    this->arrowEnable = b;
  }

  void SetFontEnable(const bool b){
    this->fontEnable = b;
  }
  bool FontEnable()const{
    return fontEnable;
  }

  QFont ItemFont()const{
    return itemFont;
  }
  void SetItemFont(const QFont font){
    this->itemFont = font;
  }

  void SetWidthEnable(const bool b){
    this->widthEnable = b;
  }
  bool WidthEnable()const{
    return widthEnable;
  }

  void SetWidth(const int width){
    this->width = width;
  }
  int Width()const{
    return width;
  }

  QColor PenColor()const{
    return penColor;
  }
  void SetPenColor(const QColor color){
    this->penColor = color;
  }

  void SetPenEnable(const bool b){
    this->penEnable = b;
  }
  bool PenEnable()const{
    return penEnable;
  }

  QColor BrushColor()const{
    return brushColor;
  }
  void SetBrushColor(const QColor color){
    this->brushColor = color;
  }

  void SetBrushEnble(const bool b){
    this->brushEnable = b;
  }
  bool BrushEnable()const{
    return brushEnable;
  }

  float ItemOpacity()const{
    return itemOpacity;
  }
  void SetItemOpacity(const float opacity){
    if (itemOpacity < 0)
      this->itemOpacity = 0;
    else if (itemOpacity >1)
      this->itemOpacity = 1;
    else
      this->itemOpacity = opacity;
  }

  void SetOpacityEnable(int b){
    opacityEnable = b;
  }
  bool OpacityEnable()const{
    return opacityEnable;
  }

  const ToolAtrribute& operator =(const ToolAtrribute& attr)
  {
    arrow = attr.Arrow();//箭头，即线形
    arrowEnable = attr.ArrowEnable();//
    itemFont = attr.ItemFont();//字体
    fontEnable = attr.FontEnable();
    width = attr.Width();//线宽
    widthEnable = attr.WidthEnable();
    penColor = attr.PenColor();//画笔颜色
    penEnable = attr.PenEnable();
    brushColor = attr.BrushColor();//填充颜色
    brushEnable = attr.BrushEnable();
    itemOpacity = attr.ItemOpacity();//取值为0至100，透明度
    opacityEnable = attr.OpacityEnable();

    return *this;
  }

  explicit ToolAtrribute(const ToolAtrribute &attr)
  {
    arrow = attr.Arrow();//箭头，即线形
    arrowEnable = attr.ArrowEnable();//
    itemFont = attr.ItemFont();//字体
    fontEnable = attr.FontEnable();
    width = attr.Width();//线宽
    widthEnable = attr.WidthEnable();
    penColor = attr.PenColor();//画笔颜色
    penEnable = attr.PenEnable();
    brushColor = attr.BrushColor();//填充颜色
    brushEnable = attr.BrushEnable();
    itemOpacity = attr.ItemOpacity();//取值为0至100，透明度
    opacityEnable = attr.OpacityEnable();
  }

  ToolAtrribute(int _width = 3,//线宽
    QColor _penColor = QColor(Qt::blue),//画笔颜色
    QColor _brushColor = QColor(Qt::green),//填充颜色
    ArrowType _arrow = LINE,//线条类型
    QFont _font = QFont("宋体"),//字体
    float _opacity = 1,
    bool _widthEnable = true,//线宽是否修改
    bool _penEnable = true,//画笔颜色是否修改
    bool _brushEnable = true,//画刷是否可修改
    bool _arrowEnable = true,//箭头是否修改，即是否可以调整线形
    bool _fontEnable = true,//字体是否可以修改
    bool _opacityEnable = true
    ) :width(_width)
    , penColor(_penColor)
    , brushColor(_brushColor)
    , arrow(_arrow)
    , itemFont(_font)
    , itemOpacity(_opacity)
    , widthEnable(_widthEnable)
    , penEnable(_penEnable)
    , brushEnable(_brushEnable)
    , arrowEnable(_arrowEnable)
    , fontEnable(_fontEnable)
    , opacityEnable(_opacityEnable)
  {}
};



#endif
