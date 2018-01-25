#ifndef _ITEM_ATTRIBUTE_H_
#define _ITEM_ATTRIBUTE_H_

#include "ToolAttribute.h"
#include "QGraphicsScene.h"
#include<QCoreApplication>
#include<QDataStream>
#include<QFile>
#include<QHash>
#include<iostream>
#include<QDebug>
#include "QGraphicsPathItem"
#include "items_export.h"
typedef std::map<qint64, std::vector<QPoint> >  TrackData;
typedef TrackData::iterator ITERATOR;

/*
 * 这个类封装了所有绘制项一些基本属性和操作
 */
class ITEMS_EXPORT ItemAttribute
{
 private:
   int startTime;//item出现的时间
   int endTime;//item消失的时间
   int fadeIn;//淡入时间
   int fadeInDuration;//淡入持续时间
   int fadeOut;//淡出时间
   int fadeOutDuration;//淡出持续时间
 public:
   TrackData trackingData;//跟踪数据
   bool trackEnble;//是否允许跟踪
 
   int targetSpeed;//跟踪目标的运动速度，其决定了跟踪时搜索范围
   bool isTracking;    //true表示跟踪
   qint64 sTracking;  //开始跟踪的时间点
   qint64 eTracking;  //结束跟踪的时间点
   qint64 curTime;//当前时间
   QGraphicsPathItem* pathItem;
   bool showTracks;//是否显示轨迹
   void SetShowTracks(const bool b){ 
     showTracks = b; 
     if (pathItem && showTracks)
     {
       pathItem->show();
     }
     else if (pathItem)
     {
       pathItem->hide();
     }
     updateAttribute();
   }
   bool ShowTracks()const{ return showTracks; }
   bool TrackEnble()const{ return trackEnble; }
   void SetTrackEnable(const bool b){ trackEnble = b; }
   //插入跟踪数据
   void insertTrackingData(qint64 time, std::vector<QPoint> points)
   {
     trackingData.insert(std::map<qint64, std::vector<QPoint> >::value_type(time, points));
   }
   //查找time时刻的跟踪数据
   ITERATOR find(qint64 time)
   {
     return trackingData.find(time);
   }
   //清空time之后的数据，主要用于手动调整后，清空调整时刻之后的跟踪数据。
   int  erase2End(qint64 time)
   {
     return erase2End(find(time));
   }
   int erase2End(ITERATOR _iter)
   {
     int count = 0;
     while (_iter != trackingData.end())
     {
       trackingData.erase(_iter++);
       count++;
     }
     return count;
   }

public:
  ToolAtrribute attr; //工具的属性
public:
  ItemAttribute(int _startTime = -1//item出现的时间
    , int _endTime = -1//item消失的时间
    , int _fadeIn = -1//淡入时间
    , int _fadeOut = -1//淡出时间
    , int _fadeInDuration = 0//淡入持续时间
    , int _fadeOutDuration = 0//淡出持续时间
    ) :startTime(_startTime)
      , endTime(_endTime)
      , fadeIn(_fadeIn)
      , fadeInDuration(_fadeInDuration)
      , fadeOut(_fadeOut)
      , fadeOutDuration(_fadeOutDuration)
      , trackEnble(false)
      , showTracks(false)
      , curTime(0) {
      isTracking = false;
      sTracking = -1;
      eTracking = -1;
      targetSpeed = 10;
      pathItem = NULL;
  }

  virtual ~ItemAttribute() {}
  
  const ItemAttribute& operator=(const ItemAttribute& attribute)
  {
     startTime = attribute.StartTime();//item出现的时间
     endTime = attribute.EndTime();//item消失的时间
     fadeIn = attribute.FadeIn();//淡入时间
     fadeInDuration = attribute.FadeInDuration();//淡入持续时间
     fadeOut = attribute.FadeOut();//淡出时间
     fadeOutDuration = attribute.FadeOutDuration();//淡出持续时间

    return *this;
  }
  explicit ItemAttribute(const ItemAttribute& attribute)
  {
    attr = attribute.attr;
    startTime = attribute.StartTime();//item出现的时间
    endTime = attribute.EndTime();//item消失的时间
    fadeIn = attribute.FadeIn();//淡入时间
    fadeInDuration = attribute.FadeInDuration();//淡入持续时间
    fadeOut = attribute.FadeOut();//淡出时间
    fadeOutDuration = attribute.FadeOutDuration();//淡出持续时间
  }
  void setToolAttribute(const ToolAtrribute& toolAtt)
  {
    attr.SetArrow(toolAtt.Arrow());
    attr.SetArrowEnable(toolAtt.ArrowEnable());

    attr.SetBrushColor(toolAtt.BrushColor());
    attr.SetBrushEnble(toolAtt.BrushEnable());
    
    attr.SetItemFont(toolAtt.ItemFont());
    attr.SetFontEnable(toolAtt.FontEnable());
    
    attr.SetItemOpacity(toolAtt.ItemOpacity());
    attr.SetOpacityEnable(toolAtt.OpacityEnable());
    
    attr.SetPenColor(toolAtt.PenColor());
    attr.SetPenEnable(toolAtt.PenEnable());

    attr.SetWidth(toolAtt.Width());
    attr.SetWidthEnable(toolAtt.WidthEnable());
  }

  int StartTime()const{
    return startTime;
  }
  void SetStartTime(const int time){
    startTime = time;
  }
  int EndTime()const{
    return endTime;
  }
  void SetEndTime(const int time){
    endTime = time;
  }
  int FadeIn()const{
    return fadeIn;
  }
  void SetFadeIn(const int time){
    fadeIn = time;
  }
  int FadeInDuration()const{
    return fadeInDuration;
  }
  void SetFadeInDuration(const int time){
    fadeInDuration = time;
  }
  int FadeOut()const{
    return fadeOut;
  }
  void SetFadeOut(const int time){
    fadeOut = time;
  }
  int FadeOutDuration()const{
    return fadeOutDuration;
  }
  void SetFadeOutDuration(const int time){
    fadeOutDuration = time;
  }
  float CurrentOpacity()
  {
    int fi = FadeIn();
    int fid = FadeInDuration();
    int fo = FadeOut();
    int fod = FadeOutDuration();
    float opacity = attr.ItemOpacity();
    qint64 ct = CurTime();

    //判断是否为立即淡入淡出
    if (fid == 0 && fi != -1)
      opacity = attr.ItemOpacity();
    if (fod == 0 && fo != -1)
      opacity = 0;
    //先淡入后淡出
    if (fi <= fo&&fo != -1){
      if (ct >= fi - fid&&ct <= fi&&fid != 0)
        opacity = (1 + (float)(ct - fi) / fid)*attr.ItemOpacity();
      else if (ct > fi&&ct<fo)
        opacity = attr.ItemOpacity();
      if (ct >= fo&&ct <= fo + fod&&fod != 0)
        opacity = (1 - (float)(ct - fo) / fod)*attr.ItemOpacity();
      if (ct <= fi - fid || ct >= fo + fod)//淡入前和淡出后不透明度都是0
        opacity = 0;
    }
    //先淡出后淡入
    else if (fi > fo&&fi != -1){
      if (ct > fo&&ct <= fo + fod&&fod != 0)//当某时刻既有淡入又有淡出时，淡出优先级高于淡入
        opacity = (1 - (float)(ct - fo) / fod)*attr.ItemOpacity();
      else if (ct >= fi - fid&&ct < fi&&fid != 0)
        opacity = (1 + (float)(ct - fi) / fid)*attr.ItemOpacity();
      if (ct>fo + fod&&ct < fi - fid)//淡出后和淡入前的不透明度为0
        opacity = 0;
      if (ct <= fo || ct >= fi)//淡出前和淡入后都是原先的不透明度
        opacity = attr.ItemOpacity();
    }
    return opacity;
  }
  const ToolAtrribute& ToolAtrribute()const{
    return attr;
  }
  qint64 CurTime()const
  {
    return curTime;
  }
  void setCurTime(const qint64& ct)
  {
    curTime = ct;
  }
public:
  //提供一些接口函数
  //添加到场景
  virtual void addToScene(QGraphicsScene* scene) = 0;
  //从场景删除
  virtual void removeFromScene(QGraphicsScene* scene) = 0;
  virtual void setItemPenColor(const QColor penColor){ attr.SetPenColor(penColor); }//画笔颜色
  virtual void setItemBrushColor(const QColor color){ attr.SetBrushColor(color); }//画刷颜色
  virtual void setItemFont(const QFont font){ attr.SetItemFont(font); }//字体
  virtual void setItemWidth(const int width){ attr.SetWidth(width); }//线宽
  virtual void setItemLineStyle(const ToolAtrribute::ArrowType style){ attr.SetArrow(style); }//线形
  virtual void setItemOpacity(const float opacity){ attr.SetItemOpacity(opacity); }//透明度取值为0至1
  virtual void updateAttribute() = 0;
  virtual QString className() = 0;
  virtual void save(QTextStream &steam) = 0;
  virtual void load(QTextStream &steam) = 0;
  virtual void showCtrlRect() = 0;
  virtual void hideCtrlRect() = 0;
  virtual bool Equals(const ItemAttribute* other) const {
    return other == this;
  }
  virtual ItemAttribute* MainItem() {
    return this;
  }
};
#endif
