//---------------------------------------------------------------------------

#include <vcl.h>
#include <math.h>
#pragma hdrstop


#include "kekkekkek.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
 float a,b,h;
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
int speed=2;
randomize();
double chislo=random(M_PI*5)-M_PI;
for(double i=0; i<=chislo; i+=M_PI/60){
Repaint();
Sleep(speed);
speed++;
Image1->Canvas->Pen->Color=clWhite;
Image1->Canvas->Brush->Color=clWhite;
Image1->Canvas->Rectangle(0,0,289,249);
Image1->Canvas->Pen->Color=clBlack;
Image1->Canvas->Ellipse(30,30,200,200);
Image1->Canvas->MoveTo(105,0);
Image1->Canvas->LineTo(105, 30);
Image1->Canvas->LineTo(115, 45);
Image1->Canvas->LineTo(125, 30);
Image1->Canvas->LineTo(125, 0);
Image1->Canvas->LineTo(105, 0);
 Image1->Canvas->Brush->Color = clRed;
 Image1->Canvas->FloodFill(115, 15, clBlack, fsBorder);
 Image1->Canvas->FloodFill(115, 40, clBlack, fsBorder);
for (double angle = 0; angle <= M_PI*2; angle += 0.785){
double xx = 115 + R*cos(angle+i);
double yy = 115 + R*sin(angle+i);

 Image1->Canvas->Brush->Color = clAqua;
 Image1->Canvas->FloodFill(116, 116, clBlack, fsBorder);

Image1->Canvas->MoveTo(115,115);
Image1->Canvas->LineTo(xx, yy);

}

}

}













//---------------------------------------------------------------------------






