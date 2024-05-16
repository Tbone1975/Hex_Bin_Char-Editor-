#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QFile>
#include <QDir>
#include <QTextStream>
//#include <QCoreApplication>



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}



//////UNIVERSAL VARIABLE DECLARATIONS//////
QString Char_Text_Prior;
QString Hex_Text_Prior;
QString Bin_Text_Prior;
QString Current_File_Name;
//////////////////////////////////////


///Basis for open file function; this function reads the text file and displays it's content in the Character text box///
void MainWindow::openFile(const QString &fileName)
{
    QFile file(fileName); //creating file object

    if(!file.open(QFile::ReadWrite|QFile::Text)) //Warning message for if file was not found or is not open
    {
        QMessageBox::warning(this,"title","file not open");
    }

    //to write to the char textbox
    QTextStream instream (&file);
    QString content = instream.readAll();
    ui ->plainTextEdit_2 ->setPlainText(content);
    file.close();
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////


///Character to Hexadecimal Converter Function////////////////////////////
void Char_to_Hex_Converter (QString CharText, QString &HexText)
{

    for(int i=0; i< CharText.length();i++)
    {
        QString Char = CharText.at(i);
        QString Hex = Char.toUtf8().toHex();
        HexText = HexText + Hex + " ";
    }
}
///////////////////////////////////////////////////////////


///Hexadecimal to Binary Converter Function///////////////////
void Hex_to_bin_Converter(QString Hex, QString &Bin)
{
    for(int i=0; i<Hex.length()-2;i++) //loop through each element of hexText
    {
        QString HexNum;
        if (Hex.at(i+2) == ' ') //to check if element is the first figure in a hexadecimal nmber
        {
            HexNum = Hex.at(i);
            HexNum.append(Hex.at(i+1));            //This part saves the 2-figure hexadecimal into a variable called HexNum

            bool ok;
            int IntegerTxt  = HexNum.toInt(&ok,16);
            QString binNumber = HexNum.setNum(IntegerTxt,2); //This code converts the HexNum to a BinNumber
            Bin = Bin + binNumber + " "; //To append the binNumber to BinValue
        }
    }
}
/////////////////////////////////////////////////////////////////


///Hexadecimal to Character Converter Function///////////////////
void Hex_to_Char_Converter(QString HexText, QString &CharText)
{
    for(int i=0; i<HexText.length()-2;i++) //loop through each element of hexText1
    {
        QString HexNum;

        if (HexText.at(i+2) == ' ') //to check if element is the first figure in a hexadecimal nmber
        {
            HexNum = HexText.at(i);
            HexNum.append(HexText.at(i+1));            //This part needs to save the 2-figure hexadecimal into a variable called HexNum

            bool ok;
            int Number = HexNum.toInt(&ok, 16);
            char Character = (char)Number;

            CharText = CharText + Character;
        }
    }
}
//////////////////////////////////////////////////////////////////

/////////Binary to Hexadecimal Converter Function/////////////////
void Bin_to_Hex_Converter(QString BinText3,QString &BinNumber2, QString &HexNumber )
{
    BinText3 = BinText3 + " ";
    for(int i=0; i<BinText3.length()-1; i++)   //to loop through each element in the binary text
    {
        if (BinText3.at(i+1) != ' ')
        {
            BinNumber2 = BinNumber2 + BinText3.at(i);
        }
        else
        {
            BinNumber2 = BinNumber2 + BinText3.at(i);
            bool fOk;
            int integer_Value = BinNumber2.toInt(&fOk, 2);  //2 is the base
            HexNumber = HexNumber + QString::number(integer_Value, 16) + " ";  //The new base is 16
            BinNumber2 = "";
        }
    }
    //The If else statements above run through the binary numbers given in the text BinText3,
    //create a QString containing a binary number based on the positions of the spaces,and
    //convert each BinNumber2 string to a HexNumber
}
/////////////////////////////////////////////////////////////





//////For the "Open" button/////////////////////////////////
void MainWindow::on_Open_Button_clicked()
{
    //Code to open the Dialog file selection box
    const QString fileName = QFileDialog::getOpenFileName(
        this,
        tr("Open file"), //title of the dialog box
        QDir::homePath(), //Default file directory
        "Text File (*.txt*)" //File type filtering
        );
    if (fileName.isEmpty())
        return;

    openFile(fileName); //To call the open file function.

    Current_File_Name = fileName; //to set the current_file_name variable to filename
    ui->label->setText(Current_File_Name);
}

/////

///FOR THE SAVE BUTTON////////////////
void MainWindow::on_Save_Button_clicked()
{
    if (Current_File_Name != "")
    {
        QFile file(Current_File_Name); //creating file object and setting it to the Current_File_Name

        if(!file.open(QFile::ReadWrite|QFile::Text)) //Warning message for if file was not found or is not open
            {
                QMessageBox::warning(this,"title","file not open");
            }
        else
            {
                QMessageBox::information(this,"Info","File saved succesfully");
            }

        //to write content from the Character textbox into the file
        QTextStream out (&file);
        QString content = ui ->plainTextEdit_2 ->toPlainText();
        out<<content;
        file.flush();
        file.close();
    }
    else //"Save As" code
    {
        //first, we get the save file name from the user through the file dialogue
        QString fileName1 = QFileDialog::getSaveFileName(this, tr("Save File"), //title of the dialog box
                                                         "C:/untitled.txt",  //Default file directory and name
                                                         tr("Text (*.txt)")); //File type filtering

        QFile file(fileName1);
        if (!file.open(QFile::WriteOnly|QFile::Text))
        {
            QMessageBox::warning(this,"title","file not open") ;
        }
        else
        {
            QMessageBox::information(this,"Info","File saved succesfully");
        }
        //to write content from the Character textbox into the file
        QTextStream out (&file);
        QString Content = ui->plainTextEdit_2->toPlainText();
        out << Content;
        file.flush();
        file.close();

        Current_File_Name = fileName1;

        ui->label->setText(Current_File_Name);
    }
}
/////////////////////////////////////////////////


///////For the "Save-As" Button//////////////////////
void MainWindow::on_Save_As_Button_clicked()
{
    //first, we get the save file name from the user through the file dialogue
    QString fileName1 = QFileDialog::getSaveFileName(this, tr("Save File"), //title of the dialog box
                                                    "C:/untitled.txt",  //Default file directory and name
                                                    tr("Text (*.txt)")); //File type filtering

    QFile file(fileName1);
    if (!file.open(QFile::WriteOnly|QFile::Text))
    {
        QMessageBox::warning(this,"title","file not open") ;
    }
    else
    {
        QMessageBox::information(this,"Info","File saved succesfully");
    }

    //to write content from the Character textbox into the file
    QTextStream out (&file);
    QString Content = ui->plainTextEdit_2->toPlainText();
    out << Content;
    file.flush();
    file.close();

    Current_File_Name = fileName1;

    ui->label->setText(Current_File_Name);
}
////////////////////////////////////////////



//////////For the "New" Button//////////
void MainWindow::on_New_Button_clicked()
{
    QString CharText_Check = ui->plainTextEdit_2->toPlainText();


    if (!CharText_Check.isEmpty()) //To check if there is unsaved work in the character text box
    {
        QMessageBox::warning(this,"Please Note"," Creating a new file will automatically save the edited character data");
        ///Save Code///
        if (Current_File_Name != "")
        {
            QFile file(Current_File_Name); //creating file object and setting it to the Current_File_Name

            if(!file.open(QFile::ReadWrite|QFile::Text)) //Warning message for if file was not found or is not open
            {
                QMessageBox::warning(this,"title","file not open");
            }
            else
            {
                QMessageBox::information(this,"Info","File saved succesfully");
            }

         //to write content from the Character textbox into the file
         QTextStream out (&file);
         QString content = ui ->plainTextEdit_2 ->toPlainText();
         out<<content;
         file.flush();
         file.close();
        }
        else //"Save As" code
        {
             //first, we get the save file name from the user through the file dialogue
             QString fileName1 = QFileDialog::getSaveFileName(this, tr("Save File"), //title of the dialog box
                                                              "C:/untitled.txt",  //Default file directory and name
                                                              tr("Text (*.txt)")); //File type filtering

             QFile file(fileName1);
             if (!file.open(QFile::WriteOnly|QFile::Text))
             {
                 QMessageBox::warning(this,"title","file not open") ;
             }
             else
             {
                 QMessageBox::information(this,"Info","File saved succesfully");
             }
             //to write content from the Character textbox into the file
             QTextStream out (&file);
             QString Content = ui->plainTextEdit_2->toPlainText();
             out << Content;
             file.flush();
             file.close();

             Current_File_Name = fileName1;

             ui->label->setText(Current_File_Name);
        }
    }

    ////////////////////////////////////

    ////Resetting values////
    QString Empty = "";
    ui->plainTextEdit_2->setPlainText(Empty);
    ui->plainTextEdit->setPlainText(Empty);
    ui->plainTextEdit_3->setPlainText(Empty);
    Current_File_Name = Empty;
    ui->label->setText(Current_File_Name);

}


////////////////CONVERT BUTTON CODE////////////////////////////
void MainWindow::on_Convert_Button_clicked()
{
    //Before any changes are made, the text in all three text boxes are stored as variables for later comparisons
    QString CharText_Current = ui->plainTextEdit_2->toPlainText();
    QString HexText_Current = ui->plainTextEdit->toPlainText();
    QString BinText_Current = ui->plainTextEdit_3->toPlainText();


    if (!CharText_Current.isEmpty() && (HexText_Current.isEmpty()) && (BinText_Current.isEmpty())) //Sequence if only character data is available
    {
        //////////////Character to Hexadecimal conversion////////////////
        QString CharText = ui->plainTextEdit_2->toPlainText(); //to get text from the character text box
        QString HexText;

        Char_to_Hex_Converter(CharText,HexText);

        ui ->plainTextEdit ->setPlainText(HexText); //display converted hexadecimal data
        /////////////////////////////////////////////////////


        //////////////////////Hexadecimal to Binary Conversion/////////////////////////
        QString HexText1 = ui->plainTextEdit->toPlainText(); //to get text from Hexadecimal textbox
        QString BinValue;

        Hex_to_bin_Converter(HexText1, BinValue);
        ui ->plainTextEdit_3 ->setPlainText(BinValue); //Display converted binary data

        //to set the values of the prior texts for future comparison
        Char_Text_Prior = ui->plainTextEdit_2->toPlainText();
        Hex_Text_Prior = ui->plainTextEdit->toPlainText();
        Bin_Text_Prior = ui->plainTextEdit_3->toPlainText();

    }


    else if (!CharText_Current.isEmpty() && /*(!HexText_Current.isEmpty()) && (!BinText_Current.isEmpty()) &&*/ (Char_Text_Prior != CharText_Current)) //Sequence for  if the ch
    //Sequence for  if the character data is modified
    {
        //////////////Character to Hexadecimal conversion////////////////
        QString CharText = ui->plainTextEdit_2->toPlainText();
        QString HexText;

        Char_to_Hex_Converter(CharText,HexText);

        ui ->plainTextEdit ->setPlainText(HexText);
        /////////////////////////////////////////////////////

        //////////////////////Hexadecimal to Binary Conversion/////////////////////////
        QString HexText1 = ui->plainTextEdit->toPlainText(); //to get text from textbox2
        QString BinValue;

        Hex_to_bin_Converter(HexText1, BinValue);
        ui ->plainTextEdit_3 ->setPlainText(BinValue); //Display converted binary data

        //to set the values of the prior texts for future comparison
        Char_Text_Prior = ui->plainTextEdit_2->toPlainText();
        Hex_Text_Prior = ui->plainTextEdit->toPlainText();
        Bin_Text_Prior = ui->plainTextEdit_3->toPlainText();
        /////////////////////////////////////////////////////////////////////////
    }

    else if (/*!CharText_Current.isEmpty() && */!HexText_Current.isEmpty() && /*(!BinText_Current.isEmpty()) &&*/ (Hex_Text_Prior != HexText_Current))
    //Sequence for  if the Hexadecimal data is modified
    {
        //////////////////////Hexadecimal to Character Conversion/////////////////////////
        QString HexText2 = ui->plainTextEdit->toPlainText();
        QString CharText2;

        Hex_to_Char_Converter(HexText2,CharText2);
        ui ->plainTextEdit_2 ->setPlainText(CharText2);
        //////////////////////////////////////////////////////////////////////////

        //////////////////////Hexadecimal to Binary Conversion/////////////////////////
        QString BinText2;
        Hex_to_bin_Converter(HexText2,BinText2);
        ui ->plainTextEdit_3 ->setPlainText(BinText2);

        //to set the values of the prior texts for future comparison
        Char_Text_Prior = ui->plainTextEdit_2->toPlainText();
        Hex_Text_Prior = ui->plainTextEdit->toPlainText();
        Bin_Text_Prior = ui->plainTextEdit_3->toPlainText();
        ///////////////////////////////////////////////////////////////////////////
    }

    else if (!BinText_Current.isEmpty() && Bin_Text_Prior != BinText_Current) //Sequence if Binary datta has been modified
    {
        /////////////Binary to Hexadecimal Conversion//////////////
        QString BinText3 = ui->plainTextEdit_3->toPlainText();
        QString BinNumber2;
        QString HexNumber;
        Bin_to_Hex_Converter(BinText3,BinNumber2,HexNumber);

        ui ->plainTextEdit ->setPlainText(HexNumber);
        /////////////////////////////////////////////////////////////

        /////////////////Hexadecimal to Character Conversion////////////////////
        QString HexText3 = ui->plainTextEdit->toPlainText();
        QString CharText3;

        Hex_to_Char_Converter(HexText3,CharText3);
        ui ->plainTextEdit_2 ->setPlainText(CharText3);
        ////////////////////////////////////////////////////////////////////////

        //to set the values of the prior texts for future comparison
        Char_Text_Prior = ui->plainTextEdit_2->toPlainText();
        Hex_Text_Prior = ui->plainTextEdit->toPlainText();
        Bin_Text_Prior = ui->plainTextEdit_3->toPlainText();
    }

}




































































