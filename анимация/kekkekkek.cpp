//---------------------------------------------------------------------------

#include <vcl.h>
#include <math.h>
#pragma hdrstop


#include "kekkekkek.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
 float a,b,h;
 double xx,yy,xx1,yy1,xx2,yy2,sleep;
 double f(double x){
   double y;
   y=(exp(x)-exp(-x))/2;
   return y;
 }




TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormCreate(TObject *Sender)
{
        Edit1->Text;
        Edit2->Text;
        Edit3->Text;
        Memo1->Clear();

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
a=StrToFloat(Edit1->Text);
b=StrToFloat(Edit2->Text);
h=StrToFloat(Edit3->Text);
  for (double x=a; x<=b; x+=h)

Series1->AddXY(x,f(x));


}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)
{
Form1->DoubleBuffered=true;
int R=85;
double speed=1;
randomize();
double chislo=random(M_PI*8)-M_PI*4;
for(double i=0; i<=chislo; i+=M_PI/60){
xx1 = 115 + (R-25)*cos(i);
 yy1 = 115 + (R-25)*sin(i);
 xx2 = 115 + (R-45)*cos(i+M_PI);
yy2 = 115 + (R-45)*sin(i+M_PI);
Repaint();
Sleep(speed);
speed+=0.8;
Image1->Canvas->Pen->Color=clWhite;
Image1->Canvas->Brush->Color=clWhite;
Image1->Canvas->Rectangle(0,0,289,249);
Image1->Canvas->Pen->Width=1;
Image1->Canvas->Pen->Color=clBlack;
Image1->Canvas->Ellipse(30,30,200,200);
for (double angle = 0; angle <= M_PI*2; angle += M_PI/2){
 xx = 115 + R*cos(angle);
 yy = 115 + R*sin(angle);
Image1->Canvas->Pen->Width=1;
Image1->Canvas->MoveTo(115,115);
Image1->Canvas->LineTo(xx, yy);
}
Image1->Canvas->Brush->Color = clGreen;
Image1->Canvas->FloodFill(116, 190, clBlack, fsBorder);
Image1->Canvas->Brush->Color = clBlue;
Image1->Canvas->FloodFill(114, 190, clBlack, fsBorder);
Image1->Canvas->Brush->Color = clRed;
Image1->Canvas->FloodFill(116, 40, clBlack, fsBorder);
Image1->Canvas->Brush->Color = clYellow;
Image1->Canvas->FloodFill(112, 40, clBlack, fsBorder);
Image1->Canvas->Pen->Color=clBlack;
Image1->Canvas->Pen->Width=8;
Image1->Canvas->MoveTo(115,115);
Image1->Canvas->LineTo(xx1, yy1);
Image1->Canvas->MoveTo(115,115);
Image1->Canvas->LineTo(xx2, yy2);
}
if (sleep == 0 && xx1>115 && yy1<115)  Memo1->Lines->Add("Вы выбрали красный цвет ");
if (sleep == 0 && xx1<115 && yy1<115)  Memo1->Lines->Add("Вы выбрали жёлтый цвет ");
if (sleep == 0 && xx1>115 && yy1>115)  Memo1->Lines->Add("Вы выбрали зелёный цвет ");
if (sleep == 0 && xx1<115 && yy1>115)  Memo1->Lines->Add("Вы выбрали синий цвет ");
}













//---------------------------------------------------------------------------







