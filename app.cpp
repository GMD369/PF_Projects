#include<iostream>
#include<fstream>
#include<conio.h>
#include<string>
#include<sstream>
#include<windows.h>
using namespace std;
void gotoxy(int x,int y);
// STRUCTURE:- 

void header();
void symbol();
void bottom();
void page();
void menu();
string deleteDetails();

// USER: ADMIN FUCNTIONS:- 

void adminMenu();
void addPatient(int size,string patient[],string patientAge[],string patientID[]);
void showPatientinfo(int size,string patient[],string patientAge[],string patientID[],int countSign4);
void showDoctorInfo(int size3,string doctor[],string DoctorID[],string doctorCategory[],int countSign5);
void showNurseInfo(int size,string nurse[],string nurseAge[],string nurseID[],string nurseCategory[],int countSign6);
void showScheduleinfo(string &date);
string deleteDate();
string deleteDoctor();
string deletePatient();
string deleteLabStaff();
string deletePharStaff();
void updateLabStaff(string &name4,string &no,string &role);
void updatePharStaff(string &name5,string &ID4,string &role2);
void updatePatient(int &size,string patient[],string patientAge[],string patientID[]);
void UpdateDoctor(int &size3,string doctor[],string DoctorID[],string doctorCategory[]);
void showlabinfo(string name4,string no,string role);
void showpharinfo(string name5,string ID4,string role2);
void addDoctor(int size3,string doctor[],string DoctorID[],string doctorCategory[]);
void schedule(string &date);
void addNurse(int size,string nurse[],string nurseAge[],string nurseID[],string nurseCategory[]);
void labStaff(string &name4,string &no,string &role);
void nurseSalary(string salary[],int size,string nurse[],string nurseAge[],string nurseID[],string nurseCategory[]);
void pharStaff(string &name5,string &ID4,string &role2);
void UpdateSalary(string salary[],int countSign7,string nurse[],string nurseAge[],string nurseID[],string nurseCategory[]);
void ShowSalary(string salary[],int countSign7,string nurse[],string nurseAge[],string nurseID[],string nurseCategory[]);
void quit();

// USER: DOCTOR FUNCTIONS:-

void Doctor(int &size7,string p1[],string symptoms[],string tests[],string medicine_name[],string treat[]);
void checkUp(int size7,string p1[],string symptoms[],string tests[],string medicine_name[],string treat[],int countSign1);
void edit(int size7,string p1[],string symptoms[],string tests[],string medicine_name[],string treat[],int countSign1);
void deletePatientDetails(int size7,string p1[],string symptoms[],string tests[],string medicine_name[],string treat[],int countSign1);

// USER: PHARMACY STAFF FUNCTIONS:-


void pharUser(int &size5,string customer[],string medname[],int price[],int quan[]);
void pharDetails(int size5,string customer[],string medname[],int price[],int quan[],int countSign2);
void edit2(int size5,string customer[],string medname[],int price[],int quan[],int countSign2);
void deletePharCustomerDetails(int size5,string customer[],string medname[],int price[],int quan[],int countSign2);

// USER: LABORATORY STAFF FUNCTIONS:-

void labUser(int &size6,string cus[],string test_type[],string date1[],string price1[]);
void labDetails(int size6,string cus[],string test_type[],string date1[],string price1[],int countSign3);
void deleteLabCustomerDetails(int size6,string cus[],string test_type[],string date1[],string price1[],int countSign3);
void edit3(int size6,string cus[],string test_type[],string date1[],string price1[],int countSign3);

// STARTUP INTERFACE FUNCTIONS: 
string login(string username[],string password[],string username1,string password1,string category[],int countsign);
void startupInterface();
bool signUp(string username[],string passwords[],string username1,string category,string password1,int &countsign,string categorys[]);
void StoreUsername_Password(string username1,string password1,string category);
// FILE HANDLING FUNCTIONS:

string getField(string record, int field);
void storeDetails_LabStaff(int size6,string cus[],string test_type[],string date1[],string price1[]);
void readData(string username[],string password[],string category[], int &countSign);
void readDetails_labStaff(int size6,string cus[],string test_type[],string date1[],string price1[],int &countSign3);
void readDetails_Pharstaff(int size5,string customer[],string medname[],int price[],int quan[],int &countSign2);
void storeDetails_Pharstaff(int size5,string customer[],string medname[],int price[],int quan[]);
void readDetails_Doctor(string p1[],string symptoms[],string tests[],string medicine_name[],string treat[],int &countSign1);
void storeDetails_Doctor(string p1[],string symptoms[],string tests[],string medicine_name[],string treat[],int size7);
void store_AddPatient(int size,string patient[],string patientAge[],string patientID[]);
void store_AddDoctor(int size3,string doctor[],string DoctorID[],string doctorCategory[]);
void store_AddNurses(int size,string nurse[],string nurseAge[],string nurseID[],string nurseCategory[]);
void read_AddNurses(int size,string nurse[],string nurseAge[],string nurseID[],string nurseCategory[],int &countSign6);
void read_AddDoctor(int size3,string doctor[],string DoctorID[],string doctorCategory[],int &countSign5);
void read_AddPatinet(int size,string patient[],string patientAge[],string patientID[],int &countSign4);
void store_AddLabStaff(string name4,string no,string role);
void store_AddSchedule(string date);
void read_AddSchedule(string &date);
void store_NursesSalaries(string salary[],int size);
bool integerCheck(string s);
void read_AddPharStaff(string &name5,string &ID4,string &role2);
void store_AddPharStaff(string name5,string ID4,string role2);
void read_AddLabStaff(string &name4,string &no,string &role);
void read_NursesSalaries(int &countSign7,string salary[]);
void updateLab_customers(string cus[],string test_type[],string date1[],string price1[],int countSign3);
void updatePatient(string p1[],string symptoms[],string tests[],string medicine_name[],string treat[],int countSign1);
void updatePhar_Customers(string customer[],string medname[],int price[],int quan[],int countSign2);

int x=50,y=1;

 main()
{    
    // Local variables:
    string choice,choice1,choice2,patientAge[5000];
    string patientID[5000],date=" ",tell1,name4,role;
    string user,choice3,choice4,username[1000],doctorID[1000];
    string passwords[1000],st,nurse[1000],nurseCategory[1000];
    string categorys[1000],patient[5000],doctor[1000];
    string doctorCategory[1000],name5,role2,medicine_name[1000];
    int countSign=0,size2=0,size3,countSign1=0,countSign2=0,countSign6=0;
    int size,countSign4=0,countSign7=0;
    int size7,size5,price[1000],quan[1000],size6,countSign3=0,countSign5=0;
    string price1[1000],nurseID[1000],nurseAge[1000];
    string cus[1000],test_type[1000],date1[1000],ID4;
    string tests[1000],symptoms[1000],p1[1000],no;
    string treat[1000],customer[1000],medname[1000];
     string usernamem;
     string passwordm;
     string categorym,salary[1000]; 
     readData(username,passwords,categorys,countSign);
     readDetails_Doctor( p1,symptoms, tests, medicine_name, treat,countSign1);
     readDetails_labStaff(size6,cus, test_type, date1,price1,countSign3);
     readDetails_Pharstaff( size5, customer, medname, price, quan, countSign2);
     read_AddPatinet(size,patient, patientAge, patientID,countSign4);
     read_AddDoctor(size3, doctor,doctorID,doctorCategory,countSign5);
     read_AddLabStaff(name4,no,role);
     read_AddPharStaff(name5,ID4,role2);
     read_AddNurses( size, nurse, nurseAge,nurseID, nurseCategory,countSign6);
     read_AddSchedule(date);
     read_NursesSalaries(countSign7,salary);
    HANDLE h=GetStdHandle(STD_OUTPUT_HANDLE);
    system("cls");
    SetConsoleTextAttribute(h,4);
    page();
    getch();
    while(true)
    {
    system("cls");
    startupInterface();
    cout<<"Choose Option: ";
    cin>>choice1;
    if(choice1=="1")
    {
      // SIGN UP:
     string usernamem;
     string passwordm;
     string categorym; 
  system("cls");
  SetConsoleTextAttribute(h,8);
  header();
  SetConsoleTextAttribute(h,4);
  symbol();
  SetConsoleTextAttribute(h,9);
  bottom();
  SetConsoleTextAttribute(h,3);
  cout<<"USERS: "<<endl;
  cout<<"-----"<<endl;
  cout<<"> ADMIN(admin)"<<endl;
  cout<<"> DOCTOR(doctor)"<<endl;
  cout<<"> PHARMACY STAFF(pharstaff)"<<endl;
  cout<<"> LABORATORY STAFF(labstaff)"<<endl; 
  SetConsoleTextAttribute(h,7);
  gotoxy(x+25,y+20);
  cout<<"ENTER USERNAME HERE: ";
  gotoxy(x+25,y+23);
  cout<<"ENTER PASSWORD HERE: ";
  gotoxy(x+25,y+26);
  cout<<"ENTER CATEGORY: ";
  gotoxy(x+50,y+20);
  cin>>usernamem;
  gotoxy(x+50,y+23);
  cin>>passwordm;
  gotoxy(x+50,y+26);
  cin>>categorym;
  bool isValid=signUp(username, passwords, usernamem,categorym, passwordm, countSign, categorys);
     if (isValid)
            {
                cout << "SignedUp Successfully" << endl;
                Sleep(1000);
            }
            if (!isValid)
            {   
                cout << "SignedUp not Successfully" << endl;
                cout<<"username is already Exist";
                Sleep(1000);
            } 
    }
    else if(choice1=="2")
    {
    //SIGN IN:
    system("cls");
    SetConsoleTextAttribute(h,8);
    header();
    SetConsoleTextAttribute(h,4);
    symbol();
    SetConsoleTextAttribute(h,9);
    bottom();
    string username1;
    string password1;
    string cat,tell;
    SetConsoleTextAttribute(h,1);
    gotoxy(x+20+10+3,y+15);
    cout << "==============================\n";
    gotoxy(x+20+10+3,y+16);
    cout << "         Login Interface       \n";
    gotoxy(x+20+10+3,y+17);
    cout << "==============================\n";
    SetConsoleTextAttribute(h,7);   
     gotoxy(x+25,y+20);
    cout<<"ENTER USERNAME: ";
     gotoxy(x+25,y+23);
    cout<<"ENTER PASSWORD: ";
    gotoxy(x+45,y+20);
    cin>>username1;
     gotoxy(x+45,y+23);
     cin>>password1;
    cat=login( username, passwords, username1, password1, categorys,countSign);
       if (cat=="undefined")
       {
          gotoxy(x+25,y+30);
          cout<<"You entered wrong credentials!"<<endl<<endl;
          cout<<"Press any key to continue ";
          getch();
         
          }
  if (cat=="admin")
  {
    //USER: ADMIN INTERFACE:
    while(true)
    {
      system("cls");
    system("Color 03");
    header();
    bottom();
    cout<<endl<<endl;
    symbol();
    cout<<endl<<endl;
    string head[1]={"-------------------ADMIN------------------"};
    
    for (int i=0;i<1;i++)
    {
      gotoxy(x+20+10,y+13);
      cout<<head[i]<<endl<<endl;
    }
     adminMenu();
     bottom(); 
     cout<<"Enter your choice: ";
     cin>>choice;
     system("cls");
    if (choice == "1")
    {   

        header();
        cout<<endl<<endl;
        cout<<"                                    ...........Enter PATIENT INFO...........       "<<endl<<endl;
        cout<<"How many patients information added: ";
        while(!(cin>>size2))
   {
       cout<<"ERROR!"<<endl;
       cout<<"How many patients information added: ";
       cin.clear();
       cin.ignore(123,'\n');
   }
        addPatient(size2,patient,patientAge,patientID);
        store_AddPatient( size2,patient, patientAge, patientID);

    }
    else if (choice == "2")
    {

        header();
        showPatientinfo(size2,patient,patientAge,patientID,countSign4);
        cout<<"Do you want to delete or update the patients (d/u): ";
        cin>>tell;
    if (tell=="d")
    {
      fstream data;
      data.open("AddPatient.txt",ios::out);
      string name=deletePatient();
      for(int i=0;i<countSign4;i++)
      {
        patientID[i]=name;
        patient[i]=name;
        patientAge[i]=name;
        getline(data,name);
      }
      data.close();
    }
    if (tell=="u")
    {
      updatePatient(size2,patient,patientAge,patientID);
    }

    }
    else if (choice == "3")
    {

        header();
     cout<<"                                   -----------------Enter DOCTOR INFO-----------------"<<endl<<endl;
     cout<<"Enter how many doctors information added: ";
     while(!(cin>>size3))
   {
    cout<<"ERROR!"<<endl;
    cout<<"Enter how many doctors information added: ";
    cin.clear();
    cin.ignore(123,'\n');
   }
        addDoctor(size3,doctor,doctorID,doctorCategory);
       store_AddDoctor(size3, doctor, doctorID,doctorCategory);

    }
    else if (choice == "4")
    {

        header();
        showDoctorInfo(size3,doctor,doctorID,doctorCategory,countSign5);
         cout<<"Do you want to delete or update the Doctor INFO (d/u): ";
    cin>>st;
    if (st=="d")
    {
      fstream data1;
      data1.open("AddDoctor.txt",ios::out);
      string swap=deleteDoctor();
      for (int i=0;i<countSign5;i++)
      {
        doctor[i]=swap;
        doctorID[i]=swap;
        doctorCategory[i]=swap;
        getline(data1,swap);
      }
      data1.close();
      
    }
    if (st=="u")
    {
      UpdateDoctor(size3,doctor,doctorID,doctorCategory);
    }

    }
    else if (choice == "11")
    {

        header();
        schedule(date);
        store_AddSchedule(date);

    }
    else if (choice=="12")
    {

    header();
    showScheduleinfo(date);
    cout<<"Do You want to Delete the date (yes/no): ";
    cin>>tell1;
    if (tell1=="yes")
    {
      fstream data;
      data.open("AddAppointment.txt",ios::out);
      string st=deleteDate();
      date=st;
      data<< st;
      data.close();
      exit;
    }
    else  {
      exit;
    }
  

    }
    else if (choice=="5")
    {

     header();
    cout<<"                                   >>>>>>>>>>>>>>Enter NURSE INFO<<<<<<<<<<<<<<"<<endl<<endl;
    cout<<"How many Nurses Information Added: ";
    while(!(cin>>size))
   {
    cout<<"ERROR!"<<endl;
    cout<<"How many Nurses Information Added: ";
    cin.clear();
    cin.ignore(123,'\n');
   }
        addNurse(size,nurse,nurseAge,nurseID,nurseCategory);
        store_AddNurses(size,nurse, nurseAge,nurseID,nurseCategory);

    }
    else if (choice == "6")
    {

        header();
        showNurseInfo(size,nurse,nurseAge,nurseID,nurseCategory,countSign6);

    }
    else if (choice=="7")
    {

        header();
        labStaff(name4,no,role);
        store_AddLabStaff(name4, no, role);

    }
    else if (choice=="8")
    { 

        header();
        showlabinfo(name4,no,role);
          cout<<"Do you want to delete or update the Laboratory Staff(d/u): ";
        cin>>tell;
        if (tell=="d")
        {
          fstream data;
          data.open("AddLaboratoryStaff.txt",ios::out);
          string st=deleteLabStaff();
          name4=st;
          no=" ";
          role=" ";
          getline(data,no);
          data.close();
        }
        if (tell=="u")
        {
         updateLabStaff( name4, no, role);
        }

    }

    else if (choice=="9")
    {

        header();
        pharStaff( name5, ID4, role2);
        store_AddPharStaff(name5, ID4, role2);

    }
    else if (choice=="10")
    {

        header();
        showpharinfo( name5, ID4, role2);
         cout<<"Do you want to delete or update the Pharmacy Staff(d/u): ";
        cin>>tell;
        if (tell=="d")
        {
          fstream data;
          data.open("AddPharmacyStaff.txt",ios::out);
          string swap=deletePharStaff();
          name5=swap;
          ID4=" ";
          role2=" ";
          getline(data,swap);
          data.close();
        }
        if (tell=="u")
        {
          updatePharStaff( name5, ID4, role2);
        }

    }
    else if (choice=="13")
    {
        header();
        nurseSalary(salary,size,nurse,nurseAge,nurseID,nurseCategory);
        store_NursesSalaries(salary, size);
    }
    else if (choice=="14")
    {
        header();
        UpdateSalary(salary,countSign7,nurse,nurseAge,nurseID,nurseCategory);
    }
     else if (choice=="15")
    {
        header();
        ShowSalary(salary,countSign7,nurse,nurseAge,nurseID,nurseCategory);
    }
    else if (choice=="16")
    {

        system("cls");
        break;
    }

    else{
        cout<<"Invalid";
    }
   cout<<endl<<endl<<"Enter any key to continue ..";
   getch();
    system("cls");
    
    
    }
    }
    else if(cat=="doctor")
    {
      // USER: DOCTOR INTERFACE:
      while(true)
      {
        system("cls");
        system ("Color 0A");
        header();
        bottom();
        gotoxy(x+12+2,y+10);
        cout<<"**************************************************************************"<<endl;
        gotoxy(x+12+2,y+11);
        cout<<"*****************************DOCTOR INTERFACE*****************************"<<endl;
        gotoxy(x+12+2,y+12);
        cout<<"**************************************************************************"<<endl;
         menu();
        gotoxy(x+2,y+35);
        cout<<"choose option: ";
        gotoxy(x+18,y+35);
        cin>>choice2;
        if (choice2=="1")
        {
         system("cls");
        Doctor(size7,p1,symptoms,tests,medicine_name,treat);
        storeDetails_Doctor( p1,symptoms, tests, medicine_name, treat, size7);
        cout<<"Press any key to exit: ";
        getch();
        }
        else if(choice2=="2")
        { 
          system("cls");
          checkUp(size7,p1,symptoms,tests,medicine_name,treat,countSign1);
          cout<<"Press any key to exit: ";
          getch();
        }
        if(choice2=="3")
        {
         system("cls");
          edit(size7,p1,symptoms,tests,medicine_name,treat,countSign1);
          cout<<"Press any key to exit: ";
          getch();
        }
        if(choice2=="4")
        {
         system("cls");
          deletePatientDetails(size7,p1,symptoms,tests,medicine_name,treat,countSign1);
          updatePatient(p1,symptoms,tests,medicine_name,treat,countSign1);
          cout<<"Press any key to exit: ";
          getch();
        }
        if(choice2=="5")
        {
          break;
        }
        }
   
    
    }
    else if(cat=="pharstaff")
    {
      // USER : PHARMACY STAFF:
      while(true)
      {
        system("cls");
        system ("Color 08");
        header();
        bottom();
        gotoxy(x+12+2,y+10);
        cout<<"**************************************************************************"<<endl;
        gotoxy(x+12+2,y+11);
        cout<<"*****************************PHARMACY INTERFACE***************************"<<endl;
        gotoxy(x+12+2,y+12);
        cout<<"**************************************************************************"<<endl;
         menu();
        gotoxy(x+2,y+35);
        cout<<"choose option: ";
        gotoxy(x+18,y+35);
        cin>>choice3;
        if (choice3=="1")
        {
          system("cls");
          pharUser(size5,customer,medname,price,quan);
          storeDetails_Pharstaff( size5,customer, medname, price, quan);
          cout<<"Press any key to exit!";
          getch();
        }
        if (choice3=="2")
        {
          system("cls");
          pharDetails(size5,customer,medname,price,quan,countSign2);
          cout<<endl;
          cout<<"Press any key to exit!";
          getch();
        }
         if (choice3=="3")
        {
          system("cls");
          edit2(size5,customer,medname,price,quan,countSign2);
          cout<<"Press any key to exit!";
          getch();
        }
         if (choice3=="4")
        {
          system("cls");
          deletePharCustomerDetails(size5,customer,medname,price,quan,countSign2);
          updatePhar_Customers(customer,medname,price,quan, countSign2);
          cout<<"Press any key to exit!";
          getch();
        }
       if (choice3=="5")
        {
          break;
        } 
      }
        
        }
     else if(cat=="labstaff")
    {
      // USER: LABORATORY STAFF:
      while(true)
      {
        system("cls");
        system ("Color 04");
            header();
        bottom();
        gotoxy(x+12+2,y+10);
        cout<<"**************************************************************************"<<endl;
        gotoxy(x+12+2,y+11);
        cout<<"*****************************LABORATORY STAFF*****************************"<<endl;
        gotoxy(x+12+2,y+12);
        cout<<"**************************************************************************"<<endl;
          menu();
        gotoxy(x+2,y+35);
        cout<<"choose option: ";
        gotoxy(x+18,y+35);
        cin>>choice4;
        if (choice4=="1")
        {
          system("cls");
          labUser(size6,cus,test_type,date1,price1);
          storeDetails_LabStaff(size6, cus, test_type, date1, price1);
          cout<<"Press any key to exit!";
          getch();
        }
         if (choice4=="2")
        {
          system("cls");
          labDetails(size6,cus,test_type,date1,price1,countSign3);
          cout<<"Press any key to exit!";
          getch();
        }
         if (choice4=="3")
        {
          system("cls");
          edit3(size6,cus,test_type,date1,price1,countSign3);
          cout<<"Press any key to exit!";
          getch();
        }
         if (choice4=="4")
        {
          system("cls");
          deleteLabCustomerDetails(size6,cus,test_type,date1,price1,countSign3);
          updateLab_customers(cus,test_type,date1,price1,countSign3);
          cout<<"Press any key to exit!";
          getch();
        }
         if (choice4=="5")
        {
         break;
        }}
    
    }
    }
    
  else if(choice1=="3")
  {
    // EXIT: TERMINATES THE APPLICATION:
   return 0;
  }
  else{
    //IF USER ENTER ANY INVALID INPUTS:
        gotoxy(x+25,y+24+5);
        cout<<"Invalid!";
        Sleep(400);
        system("cls");

  }
     readData(username,passwords,categorys,countSign);
     readDetails_Doctor( p1,symptoms, tests, medicine_name, treat,countSign1);
     readDetails_labStaff(size6,cus, test_type, date1,price1,countSign3);
     readDetails_Pharstaff( size5, customer, medname, price, quan, countSign2);
     read_AddPatinet(size,patient, patientAge, patientID,countSign4);
     read_AddDoctor(size3, doctor,doctorID,doctorCategory,countSign5);
     read_AddLabStaff(name4,no,role);
     read_AddPharStaff(name5,ID4,role2);
     read_AddNurses( size, nurse, nurseAge,nurseID, nurseCategory,countSign6);
     read_AddSchedule(date);
     read_NursesSalaries(countSign7,salary);
    }
    

        
    }

void addPatient(int size,string patient[],string patientAge[],string patientID[])
{

   
    cout<<endl<<endl;
    
   for (int i=0;i<size;i++)
   {
    cout<<endl<<"Enter Patient Name: ";
    cin.ignore();
    getline(cin,patient[i]);
    cout<<"Enter Patient Age: ";
    getline(cin,patientAge[i]);
    cout<<"Enter Patient ID: ";
    getline(cin,patientID[i]);
    

}}
    void showPatientinfo(int size,string patient[],string patientAge[],string patientID[],int countSign4)
    {
      string tell;
     string face[2]={"########### PATIENT INFORMATION ##########","########################################"};
    for (int i=0;i<2;i++)
    {
      cout<<face[i]<<endl;
    }
    
   for (int j=0;j<countSign4;j++)
   {
    cout<<"ID      Name       Age"<<endl;
 
    cout <<patientID[j]<<"      "<<patient[j]<<"      "<<patientAge[j]<<endl;
    cout<<endl<<endl;
   }
     
    
     
    cout<<"Patient added successfully."<<endl;
   
}

void addDoctor(int size3,string doctor[],string DoctorID[],string doctorCategory[])
{

   
    cout<<endl<<endl;
   
    for (int i=0;i<size3;i++)
    {
    cout<<endl<<"Enter Doctor Name: ";
    cin.ignore();
    getline(cin,doctor[i]);
    cout<<"Enter Doctor ID: ";
    getline(cin,DoctorID[i]);
    cout<<"Enter Doctor Speciality: ";
    getline(cin,doctorCategory[i]);
   
}}
    void showDoctorInfo(int size3,string doctor[],string DoctorID[],string doctorCategory[],int countSign5)
{
    string face[2]={"############ DOCTOR INFORMATION ############","############################################"};
    string st;
    for (int i=0;i<2;i++)
    {
      cout<<face[i]<<endl;
    }  
    
    for (int j=0;j<countSign5;j++)
    {    
    cout<<"ID       Name        Speciality"<<endl;    
    cout <<DoctorID[j]<<"       "<<doctor[j]<<"       "<<doctorCategory[j]<<endl;
     cout<<endl<<endl;
    } 
   
    cout<<"Doctor added successfully."<<endl;
   
  
    
}
void schedule(string &date)
{
    
    ofstream write;
    write.open("Schedule.txt",ios::app);
    cout<<endl<<endl;
    cout<<"Enter Appointment date: ";
    cin.ignore();
    getline(cin,date);
    write<<endl<<date;
    write.close();

}
    void showScheduleinfo(string &date)
    {
         string tell; 
           gotoxy(x+40,y+20);
    cout<<"##### APPOINTMENT INFORMATION #####"<<endl;
       gotoxy(x+40,y+20+1);
    cout<<endl<<endl;
       gotoxy(x+40,y+20+2);
    cout<<"        DATE            "<<endl;
       gotoxy(x+40,y+20+3);
    cout<<"        "<<date<<endl;
       gotoxy(x+40,y+20+4);
    cout<<endl<<endl;
       gotoxy(x+40,y+20+5);
    cout<<"Appointment Scheduled successfully."<<endl;
   
    bottom();
    
}
 void header()
 { 

 gotoxy(x+10,y); 
 cout << "   H   H   EEEEE    A     L      TTTTT  H   H    W     W     A   V       V  EEEEE" <<endl;
 gotoxy(x+10,y+1);
 cout << "   H   H   E       A A    L        T    H   H    W     W    A A   V     V   E" <<endl;
 gotoxy(x+10,y+2);
 cout << "   HHHHH   EEEE   A A A   L        T    HHHHH    W     W   A A A   V   V    EEEE" <<endl;
 gotoxy(x+10,y+3);
 cout << "   H   H   E      A   A   L        T    H   H    W  w  W   A   A    V V     E" <<endl;
 gotoxy(x+10,y+4);
 cout << "   H   H   EEEEE  A   A   LLLLL    T    H   H    W     W   A   A     V      EEEEE" <<endl;

    } 
  void addNurse(int size,string nurse[],string nurseAge[],string nurseID[],string nurseCategory[])
  {
   
    
    cout<<endl<<endl;
   
    for (int i=0;i<size;i++)
    {
    cout<<"Enter Nurse name: ";
    cin.ignore();
    getline(cin,nurse[i]);
    cout<<"Enter Nurse age: ";
      while(!(cin>>nurseAge[i]))
   {
    cout<<"ERROR!"<<endl;
    cout<<"Enter Nurse age: ";
    cin.clear();
    cin.ignore(123,'\n');
   }
    cout<<"Enter Nurse ID: ";
      while(!(cin>>nurseID[i]))
   {
    cout<<"ERROR!"<<endl;
    cout<<"Enter Nurse ID: ";
    cin.clear();
    cin.ignore(123,'\n');
   }
    cout<<"Enter Specialization: ";
     cin.ignore();
    getline(cin,nurseCategory[i]);
  
  }
  }
    void showNurseInfo(int size,string nurse[],string nurseAge[],string nurseID[],string nurseCategory[],int countSign6)
    {      
     cout<<endl<<endl;
     string face[3]={"----------------------------------------------------------------","#####################  NURSE INFORMATION  ######################","----------------------------------------------------------------"};
      for (int i=0;i<3;i++)
      {
        cout<<face[i]<<endl;
      }
     for (int j=0;j<countSign6;j++)
      {

     cout<<"Name                ID          Age               Specialization"<<endl;
        
     cout<<nurse[j]<<"               "<<nurseID[j]<<"           "<<nurseAge[j]<<"                 "<<nurseCategory[j]<<endl;
      
     cout<<endl<<endl;
      }
       
     cout<<"Nurse Added successfully.";
     gotoxy(x+5,y+27+12);
      bottom();
    }
      void labStaff(string &name4,string &no,string &role)
      {

        cout<<endl<<endl;
        cout<<"                           ...............Enter LABORATORY STAFF INFO................."<<endl<<endl;
        cout<<"Enter Staff name: ";
         cin.ignore();
         getline(cin,name4);
        cout<<"Enter Staff ID:  ";
      while(!(cin>>no))
   {
        cout<<"ERROR!"<<endl;
        cout<<"Enter Staff ID: ";
        cin.clear();
        cin.ignore(123,'\n');
   }
        cout<<"Enter Staff Role: ";
        cin.ignore();
        getline(cin,role);
      

      }

      void showlabinfo(string name4,string
       no,string role)
      {
        cout<<endl;
        cout<<endl;
        cout<<"############# Laboratory Staff Information ###############"<<endl<<endl;
        cout<<"Name                  Staff ID             Role"<<endl;
        cout<<name4<<"               "<<no<<"                 "<<role<<endl;
        cout<<endl<<endl;
        cout<<"Laboratory Staff Added Successfully."<<endl;
    
    
      }
      void pharStaff(string &name5,string &ID4,string &role2)
      {

        cout<<endl<<endl;
        cout<<"                          ..................Enter PHARMACY STAFF INFO................."<<endl<<endl;
        cout<<"Enter Staff name: ";
        cin.ignore();
        getline(cin,name5);
        cout<<"Enter Staff ID: ";
          while(!(cin>>ID4))
   {
       cout<<"ERROR!"<<endl;
       cout<<"Enter Staff ID: ";
       cin.clear();
       cin.ignore(123,'\n');
   }
        cout<<"Enter Staff Role: ";
         cin.ignore();
        getline(cin,role2);
        
      }
        void showpharinfo(string name5,string ID4,string role2)
        {
          string tell;
        cout<<endl<<endl;
           gotoxy(x+40,y+20);
        cout<<"############### PHARMACY STAFF INFORMATION ################"<<endl<<endl;
           gotoxy(x+40,y+20+1);
        cout<<"Name                  Staff ID             Role"<<endl;
           gotoxy(x+40,y+20+2);
        cout<<name5<<"                 "<<ID4<<"                "<<role2<<endl;
           gotoxy(x+40,y+20+3);
        cout<<endl<<endl;
           gotoxy(x+40,y+20+4);
        cout<<"Pharmacy Staff Added SuccessFully."<<endl;
       
      
      }
      void symbol()
      {
        Sleep(100); 
         gotoxy(x+45,y+13);
       cout<<"       @";
       Sleep(100);
        gotoxy(x+45,y+12);
      cout<<"      @@@@";
      Sleep(100);
         gotoxy(x+45,y+11);
      cout<<"    @@@@@@@@";
      Sleep(100);
        gotoxy(x+45,y+10);
      cout<<"  @@@@@@@@@@@@";
      Sleep(100);
      gotoxy(x+45,y+9);
      cout<<" @@@@@@@@@@@@@@";
      Sleep(100);
    gotoxy(x+45,y+8);
      cout<<"@@@@@@@@@@@@@@@@@";
      Sleep(100);
         gotoxy(x+45,y+7);
      cout<<" @@@@@@   @@@@@@";
       Sleep(100);
       gotoxy(x+45,y+6);
       cout<<"  @@@       @@@";
   
     


      }
      void gotoxy(int x,int y)
{
   
    COORD coordinates;
    coordinates.X = x;
    coordinates.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);


}
bool pass(string password,string user)
{

 
    if (password=="gmd369"&&user=="gmd369")
    {

        return true;

    }
    else{

        return false;

    }
}
void nurseSalary(string salary[],int size,string nurse[],string nurseAge[],string nurseID[],string nurseCategory[])
{
  for (int i=0;i<size;i++)
  {
    cout<<"Enter Salary of "<<nurse[i]<<" "<<nurseID[i]<<" : ";
        cin>>salary[i];
    cout<<endl;
  }  

}

void UpdateSalary(string salary[],int countSign7,string nurse[],string nurseAge[],string nurseID[],string nurseCategory[])
{ 
  string checkId;
 cout<<"Enter Nurse Id: ";
   cin>>checkId;
 for (int i=0;i<countSign7;i++)
 {
   if (checkId==nurseID[i])
   {
    cout<<"Name: "<<nurse[i]<<endl;
    cout<<"Enter Update Salary: ";
    cin>>salary[i];
   }
 }

}
void ShowSalary(string salary[],int countSign7,string nurse[],string nurseAge[],string nurseID[],string nurseCategory[])
{
    cout<<"########################################################################"<<endl;
    for(int i=0;i<countSign7;i++)
    {
    cout<<"* NAME:                                            "<<nurse[i]<<endl;
    cout<<"* ID  :                                            "<<nurseID[i]<<endl;
    cout<<"************************************************************************"<<endl;
    cout<<"  SALARY:                                          "<<salary[i]<<endl;
    cout<<"########################################################################"<<endl;
    }
}
void Doctor(int &size7,string p1[],string symptoms[],string tests[],string medicine_name[],string treat[])
{

    header();
    symbol();
    string face[3]={"************************************************************","****************************DOCTOR**************************","************************************************************"};
    for (int i=0;i<3;i++)
    {
      cout<<face[i]<<endl;
    }
    cout<<endl<<endl;
    cout<<"Enter How many Patient details Added: ";
            while(!(cin>>size7))
   {
       cout<<"ERROR!"<<endl;
       cout<<"Enter How many Patient details Added: ";
       cin.clear();
       cin.ignore(123,'\n');
   }
    for (int i=0;i<size7;i++)
    {
      cout<<endl<<endl;
    cout<<"Patient Name: ";
    cin.ignore();
    getline(cin,p1[i]);
    cout<<"Patient's Symptoms: ";
    getline(cin,symptoms[i]);
    cout<<"Required Medical Tests: ";
    getline(cin,tests[i]);
    cout<<"Medicines: ";
    getline(cin,medicine_name[i]);
    cout<<"Treatment Plan: ";
    getline(cin,treat[i]);
    
    }
    
    

}
void edit(int size7,string p1[],string symptoms[],string tests[],string medicine_name[],string treat[],int countSign1)
{

  string checkPatient;
  header();
  cout<<"Enter Patient name to change the details: ";
  cin.ignore();
    getline(cin,checkPatient);

  for (int i=0;i<countSign1;i++)
  {
    fstream data2;
    data2.open("PatientDetails.txt",ios::app);

    if(p1[i]==checkPatient)
    {
      data2<<p1[i]<<",";
      cout<<"EDIT: "<<endl<<endl;
      cout<<"Patient's Symptoms: ";
      getline(cin,symptoms[i]);
      data2<<symptoms[i]<<",";
    
    cout<<"Required Medical Tests: ";
    getline(cin,tests[i]);
   data2<<tests[i]<<",";
   
    cout<<"Medicines: ";
    getline(cin,medicine_name[i]);
    data2<<medicine_name[i]<<",";
    cout<<"Treatment Plan: ";
      getline(cin,treat[i]);
   data2<<treat[i];
   data2<<endl;
   data2.close();

    }
  }
  

}
void checkUp(int size7,string p1[],string symptoms[],string tests[],string medicine_name[],string treat[],int countSign1)
{
  header();
        
    cout<<"******************************************************"<<endl;
    for(int i=0;i<countSign1;i++)
    {
    
    cout<<"PATIENT:                          "<<p1[i]<<endl;
    
    cout<<"SYMPTOM'S:                        "<<symptoms[i]<<endl;
  
    cout<<"MEDICAL TESTS:                    "<<tests[i]<<endl;
     
    cout<<"MEDICINES:                        "<<medicine_name[i]<<endl;
 
    cout<<"TREATMENT PLAN:                   "<<treat[i]<<endl;
  
    cout<<"*******************************************************"<<endl;
}

}
bool doctorPass(string user,string password)
{
 
    if (user=="doctor12"&& password=="doctor12")
    {

        return true;

    }
    else{

        return false;

    }
}
void pharUser(int &size5,string customer[],string medname[],int price[],int quan[])
{

   header();
   symbol();
   
   cout<<endl;
   string face[3]={"-------------------------------------------------------------------","-------------------------------PHARMACY----------------------------","-------------------------------------------------------------------"}; 
   for (int i=0;i<3;i++)
   {
    cout<<face[i]<<endl;
   }
   cout<<endl;
 
   cout<<"Enter How many customers detailed Added: ";
      while(!(cin>>size5))
   {
    cout<<"ERROR!"<<endl;
    cout<<"Enter How many customers detailed Added: ";
    cin.clear();
    cin.ignore(123,'\n');
   }
   for (int i=0;i<size5;i++)
   {
   cout<<"Customer Name: ";
    cin.ignore();
    getline(cin,customer[i]);
   cout<<"Medicine Name: ";
   getline(cin,medname[i]);
   cout<<"Price: ";
   while(!(cin>>price[i]))
   {
    cout<<"ERROR!"<<endl;
    cout<<"Price: ";
    cin.clear();
    cin.ignore(123,'\n');
   } 
   cout<<"Quantity: ";
   while(!(cin>>quan[i]))
   {
    cout<<"ERROR!"<<endl;
    cout<<"Quantity: ";
    cin.clear();
    cin.ignore(123,'\n');
   }
   cout<<endl<<endl;
   

}

}
void edit2(int size5,string customer[],string medname[],int price[],int quan[],int countSign2)
{ 
  string checkCus;
   header();
   cout<<"Enter Customer Name to Update the details: ";
   cin.ignore();
    getline(cin,checkCus);
   for (int i=0;i<countSign2;i++)
   {
    if (customer[i]==checkCus)
    {
      fstream data;
      data.open("Pharmacy_Customers_Details.txt",ios::app);
      data<<customer[i]<<",";
      cout<<"EDIT: "<<endl<<endl;
      cout<<"Medicine Name: ";
      getline(cin,medname[i]);
      data<<medname[i]<<",";
   
   cout<<"Price: ";
   while(!(cin>>price[i]))
   {
    cout<<"ERROR!"<<endl;
    cout<<"Price: ";
    cin.clear();
    cin.ignore(123,'\n');
   } 
   data<<price[i]<<",";
   cout<<"Quantity: ";
   while(!(cin>>quan[i]))
   {
    cout<<"ERROR!"<<endl;
    cout<<"Quantity: ";
    cin.clear();
    cin.ignore(123,'\n');
   }
   data<<quan[i];
   data<<endl;
   data.close();
  
   cout<<endl<<endl; 
    }
   }
}

void pharDetails(int size5,string customer[],string medname[],int price[],int quan[],int countSign2)
{
  int total1;
  header();
for (int i=0;i<countSign2;i++)
{   
  int total1;
    total1=price[i]*quan[i];
      cout<<endl<<endl;
    cout<<"************************************************************"<<endl;
      
    cout<<"CUSTOMER NAME:                             "<<customer[i]<<endl;
      
    cout<<"************************************************************"<<endl;
     
    cout<<"MEDICINE NAME:                             "<<medname[i]<<endl;
      
    cout<<"PRICE:                                     "<<price[i]<<endl;
    
    cout<<"QUANTITY:                                  "<<quan[i]<<endl;
      
    cout<<"************************************************************"<<endl;
   
    cout<<"TOTAL AMOUNT                               "<<total1;

}}
bool pharPass(string user,string password)
{

    if(user=="pharmacy"&&password=="pharmacy")
    {
        return true;
    }
    else{
        return false;
    }

}
void labUser(int &size6,string cus2[],string test_type[],string date1[],string price1[])
{

   header();
   symbol();
   cout<<endl<<endl;
   cout<<"------------------------LABORATORY-------------------------"<<endl<<endl;
   cout<<"Enter how many patient Details Added: ";
    while(!(cin>>size6))
   {
    cout<<"ERROR!"<<endl;
    cout<<"Enter how many patient Details Added: ";
    cin.clear();
    cin.ignore(123,'\n');
   }
   for (int i=0;i<size6;i++)
   {
   cout<<"Patient Name: ";
   cin.ignore();
    getline(cin,cus2[i]);
   cout<<"Medical Test Type: ";
    getline(cin,test_type[i]);
   cout<<"Receiving date: ";
   getline(cin,date1[i]);
   cout<<"Enter Price: ";
   while(!(cin>>price1[i]))
   {
    cout<<"ERROR!"<<endl;
    cout<<"Enter Price: ";
    cin.clear();
    cin.ignore(123,'\n');
    
   }
   
   cout<<endl<<endl;
}

}
void edit3(int size6,string cus[],string test_type[],string date1[],string price1[],int countSign3)
{
  string check2Patient;
  header();
  cout<<"Enter customer name to update the details: ";
  cin.ignore();
    getline(cin,check2Patient);
  for (int i=0;i<size6;i++)
  {
    if (cus[i]==check2Patient)
    {
      fstream data;
      data.open("Laboratory_Customer_details.txt",ios::app);
      data<<cus[i]<<",";
       cout<<"EDIT: "<<endl<<endl;
       cout<<"Medical Test Type: ";
       getline(cin,test_type[i]);
       data<<test_type[i]<<",";

        cout<<"Receiving date: ";
        getline(cin,date1[i]);
        data<<date1[i]<<",";
  
        cout<<"Enter Price: ";
        cin>>price1[i];
        data<<price1[i];
        data<<endl;
        data.close();
    }
  }
}
void labDetails(int size6,string cus[],string test_type[],string date1[],string price1[],int countSign3)
{
   header();
for (int i=0; i<countSign3;i++)
{
    
    cout<<"*******************************************************"<<endl;
    
    cout<<"PATIENT NAME:                       "<<cus[i]<<endl;
    
    cout<<"*******************************************************"<<endl;
   
    cout<<"MEDICAL TEST TYPE:                  "<<test_type[i]<<endl;
   
    cout<<"RECEIVING DATE:                     "<<date1[i]<<endl;

    cout<<"*******************************************************"<<endl;
    
    cout<<"AMOUNT:                             "<<price1[i];
    cout<<endl<<endl;

}
bottom();
}


void bottom()
{
    gotoxy(x+13,y+27+12);
    cout<<"*****************************************************************************"<<endl;
    gotoxy(x+13,y+27+1+12);
    cout<<"*****************************************************************************"<<endl;
    gotoxy(x+13,y+27+2+12);
    cout<<"************************CONSOLE BASED APPLICATION****************************"<<endl;
    gotoxy(x+13,y+27+3+12);
    cout<<"*****************************************************************************"<<endl;
    gotoxy(x+13,y+27+4+12);
    cout<<"*****************************************************************************"<<endl;
}
void startupInterface()
{
  HANDLE h=GetStdHandle(STD_OUTPUT_HANDLE);
     SetConsoleTextAttribute(h,8);
    header();
     SetConsoleTextAttribute(h,4);
    symbol();
    SetConsoleTextAttribute(h,7);
    gotoxy(x+25,y+20);
    cout<<"---> 1. SIGN UP"<<endl;
    gotoxy(x+25,y+23);
    cout<<"---> 2. LOGIN"<<endl;
    gotoxy(x+25,y+26);
    cout<<"---> 3. EXIT"<<endl;
     SetConsoleTextAttribute(h,9);
    bottom();
}
bool signUp(string username[],string passwords[],string username1,string category,string password1,int &countsign,string categorys[])
{
  
      bool isPresent = false;

    for (int index = 0; index < countsign; index++)
    {
        if (username[index] == username1 && passwords[index] == password1)
        {
            isPresent = true;
            break;
        }
    }
    if (isPresent == true)
    {
        return 0;     
    }
    else if (countsign < 1000)
    {
        username[countsign] = username1;
        passwords[countsign] = password1;
        categorys[countsign] = category;
        StoreUsername_Password(username1,password1,category);
        countsign++;
        return true;
    }
    else
    {
        return false;
    }
 
}
string login(string username[],string password[],string username1,string password1,string category[],int countsign)
{
  for (int index = 0; index < countsign; index++)
    {
        if (username[index] == username1 && password[index] == password1)
        {
            return category[index];
        }
    }
    return "undefined";
}
void page()
{
  header();
  gotoxy(x+25,y+20);
   cout<<"          +&-"<<endl;
    gotoxy(x+25,y+20+1);
   cout<<"                          _.-^-._    .--."<<endl;
   gotoxy(x+25,y+20+2);
   cout<<"                       .-'   _   '-. |__|"<<endl;
    gotoxy(x+25,y+20+3);
   cout<<"                      /     |_|     \\|  |"<<endl;
  gotoxy(x+25,y+20+4);
   cout<<"                     /               \\  |"<<endl;
   gotoxy(x+25,y+20+5);
   cout<<"                    /|     _____     |\\ |"<<endl;
  gotoxy(x+25,y+20+6);
   cout<<"                     |    |==|==|    |  |"<<endl;
   gotoxy(x+25,y+20+7);
   cout<<" |---|---|---|---|---|    |--|--|    |  |"<<endl;
 gotoxy(x+25,y+20+8);
   cout<<" |---|---|---|---|---|    |==|==|    |  |"<<endl;
 gotoxy(x+25,y+20+9);
   cout<<"^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^"<<endl<<endl<<endl;
 gotoxy(x+25,y+20+15);
  cout<<"                      LOADING.....";

}
void menu()
{
 string Menu[5]={"1. ADD DETAILS","2. VIEW DETAILS","3. EDIT DETAILS","4. DELETE DETAILS","5. EXIT"};
          for (int j=0;j<5;j++)
          {  
            if (j==0)
            {
            gotoxy(x+25,y+21+j);
              cout<<Menu[j];
          }
          if (j==1)
            {
            gotoxy(x+25,y+21+j+1);
              cout<<Menu[j];
          }
          if (j==2)
            {
            gotoxy(x+25,y+21+j+2);
              cout<<Menu[j];
          }
          if (j==3)
            {
            gotoxy(x+25,y+21+j+3);
              cout<<Menu[j];
          }
          if (j==4)
            {
            gotoxy(x+25,y+21+j+4);
              cout<<Menu[j];
          }
          }
}
string deleteDate()
{
     string date="";
     return date;
}
string deleteDoctor()
{
  string name=" ";
  return name;
}
void UpdateDoctor(int &size3,string doctor[],string DoctorID[],string doctorCategory[])
{
  fstream data;
  data.open("AddDoctor.txt",ios::app);
  cout<<"Enter how many doctors information added: ";
     while(!(cin>>size3))
   {
    cout<<"ERROR!"<<endl;
    cout<<"Enter how many doctors information added: ";
    cin.clear();
    cin.ignore(123,'\n');
   }
    for (int i=0;i<size3;i++)
    {
    cout<<endl<<"Enter Doctor Name: ";
    cin.ignore();
    getline(cin,doctor[i]);
    data<<doctor[i]<<",";
   
    cout<<"Enter Doctor ID: ";
    getline(cin,DoctorID[i]);
    data<<DoctorID[i]<<",";
   
    cout<<"Enter Doctor Speciality: ";
    getline(cin,doctorCategory[i]);
    data<<doctorCategory[i];
    data<<endl;
}
data.close();
}
string deletePatient()
{
  string st;
  st=" ";
  return st;
}
void updatePatient(int &size,string patient[],string patientAge[],string patientID[])
{
  fstream data;
  data.open("AddPatient.txt",ios::app);
      cout<<"How many patients information added: ";
      while(!(cin>>size))
   {
    cout<<"ERROR!"<<endl;
    cout<<"How many patients information added: ";
    cin.clear();
    cin.ignore(123,'\n');
   }
   for (int i=0;i<size;i++)
   {
    cout<<endl<<"Enter Patient Name: ";
    cin.ignore();
    getline(cin,patient[i]);
    data<<patient[i]<<",";
    cout<<"Enter Patient Age: ";
    getline(cin,patientAge[i]);
    data<<patientAge[i]<<",";
    cout<<"Enter Patient ID: ";
   getline(cin,patientID[i]);
   data<<patientID[i];
   data<<endl;

   }
   data.close();
   }
   string deleteLabStaff()
   {
    string st;
    st=" ";
    return st;
   }
void updateLabStaff(string &name4,string &no,string &role)
   {
        fstream data;
        data.open("AddLaboratoryStaff.txt");
        cout<<"Enter Staff name: ";
        cin.ignore();
        getline(cin,name4);
        data<<name4<<",";
        cout<<"Enter Staff ID:  ";
        cin>>no;
        data<<no<<",";
        cout<<"Enter Staff Role: ";
        cin.ignore();
        getline(cin,role);
        data<<role;
        data<<endl;
        data.close();
  

   }
   string deletePharStaff()
   {
    string st;
    st=" ";
    return st;
   }
   void updatePharStaff(string &name5,string &ID4,string &role2)
   {
    fstream data;
    data.open("AddPharmacyStaff.txt",ios::app);
     cout<<"Enter Staff name: ";
         cin.ignore();
         getline(cin,name5);
        data<<name5<<",";
        cout<<"Enter Staff ID: ";
         cin.ignore();
         getline(cin,ID4);
        data<<ID4<<",";
        cout<<"Enter Staff Role: ";
        cin.ignore();
        getline(cin,role2);
        data<<role2;
        data<<endl;
        data.close();
      
   }
   string deleteDetails()
   {
    string st=" ";
    return st;
   }
   void deletePatientDetails(int size7,string p1[],string symptoms[],string tests[],string medicine_name[],string treat[],int countSign1)
   {
    header();
    
    string cus;
    cout<<"Enter Patient Name: ";
    cin.ignore();
    getline(cin,cus);
    string swap=deleteDetails();
    for (int i=0;i<countSign1;i++)
    {
      if(cus==p1[i])
      {
      p1[i]=swap;
      treat[i]=swap;
      medicine_name[i]=swap;
      tests[i]=swap;
      symptoms[i]=swap;
      }
      bottom();
    }
    checkUp(size7,p1,symptoms,tests,medicine_name,treat,countSign1);
   }
   void deleteLabCustomerDetails(int size6,string cus[],string test_type[],string date1[],string price1[],int countSign3)
   {
    header();
    string cuss;
    cout<<"Enter Customer Name: ";
    cin>>cuss;
    string swap=deleteDetails();
    for (int i=0;i<countSign3;i++)
    {
      if (cuss==cus[i])
    {
       cus[i]="";
       test_type[i]="";
       date1[i]="";
       price1[i]="";

    }
    }
    bottom();
    labDetails(size6,cus,test_type,date1,price1,countSign3);
   }
   void deletePharCustomerDetails(int size5,string customer[],string medname[],int price[],int quan[],int countSign2)
   {
    header();
    string cus;
    cout<<"Enter Customer Name: ";
    cin>>cus;
    string swap=deleteDetails();
    for (int i=0;i<countSign2;i++)
    {
      if(cus==customer[i])
      {
     customer[i]=swap;
     medname[i]=swap;
     price[i]=0;
     quan[i]=0;
    }}
    bottom();
    pharDetails(size5,customer,medname,price,quan,countSign2);
   }
  void adminMenu()
  {
    // ADMIN MENU:
     gotoxy(x+12,y+10+5);
    cout<<"################################################################################"<<endl;
    gotoxy(x+12,y+11+5);
    cout<<"1. Add Patient                                                                 #"<<endl;
    gotoxy(x+12,y+12+5);
    cout<<"2. View patient info                                                           #"<<endl;
    gotoxy(x+12,y+13+5);
    cout<<"3. Add Doctor                                                                  #"<<endl;
    gotoxy(x+12,y+14+5);
    cout<<"4. View doctor info                                                            #"<<endl;
    gotoxy(x+12,y+15+5);
    cout<<"5. Add nurse                                                                   #"<<endl;
    gotoxy(x+12,y+16+5);
    cout<<"6. View nurse info                                                             #"<<endl;
    gotoxy(x+12,y+17+5);
    cout<<"7. Add Laboratory Staff                                                        #"<<endl;
    gotoxy(x+12,y+18+5);
    cout<<"8. View Laboratory staff                                                       #"<<endl;
    gotoxy(x+12,y+19+5);
    cout<<"9. Add Pharmacy Staff                                                          #"<<endl;
    gotoxy(x+12,y+20+5);
    cout<<"10. View Pharmacy staff                                                        #"<<endl;
    gotoxy(x+12,y+21+5);
    cout<<"11. Schedule Appointment                                                       #"<<endl;
    gotoxy(x+12,y+22+5); 
    cout<<"12. View Schedule Appointment                                                  #"<<endl;
    gotoxy(x+12,y+23+5);
    cout<<"13. Nurses Salaries                                                            #"<<endl;
    gotoxy(x+12,y+24+5);
    cout<<"14. Edit Salaries                                                              #"<<endl;
     gotoxy(x+12,y+25+5);
    cout<<"15. View Salaries                                                              #"<<endl;
    gotoxy(x+12,y+26+5);
    cout<<"16. Quit                                                                       #"<<endl;
    gotoxy(x+12,y+27+5);
    cout<<"################################################################################"<<endl<<endl<<endl;
  }
void StoreUsername_Password(string username,string password,string category)
{
  fstream data;
  data.open("Username.txt",ios::app);
  data<<username<<",";
  data<<password<<",";
  data<<category;
  data<<endl;
  data.close();
}
string getField(string record, int field)
{
int commaCount = 1;
string item = "";
for (int x = 0; x < record.length(); x++)
{
if (record[x] == ',')
{
commaCount = commaCount + 1;
}
else if (commaCount == field)
{
item = item + record[x];
}
}
return item;
}
void readData(string username[],string password[],string category[],int &countSign)
{
string record;
fstream data;
data.open("Username.txt", ios::in);
while (!(data.eof()))
{
getline(data, record);
if(!record.empty())
{
username[countSign] = getField(record, 1);
password[countSign] = getField(record, 2);
category[countSign] = getField(record, 3);
countSign = countSign + 1;
}
}
data.close();
}
void storeDetails_Doctor(string p1[],string symptoms[],string tests[],string medicine_name[],string treat[],int size7)
{
  fstream data;
  data.open("PatientDetails.txt",ios::app);
  for(int c=0;c<size7;c++)
  {
    data<<p1[c]<<",";
    data<<symptoms[c]<<",";
    data<<tests[c]<<",";
    data<<medicine_name[c]<<",";
    data<<treat[c];
    data<<endl;
      
    }
}
void readDetails_Doctor(string p1[],string symptoms[],string tests[],string medicine_name[],string treat[],int &countSign1)
{
  
string record;
fstream data;
data.open("PatientDetails.txt", ios::in);
while (!(data.eof()))
{
getline(data, record);
if(!record.empty())
{
p1[countSign1] = getField(record, 1);
symptoms[countSign1] = getField(record, 2);
tests[countSign1] = getField(record, 3);
medicine_name[countSign1] = getField(record, 4);
treat[countSign1] = getField(record, 5);
countSign1 = countSign1 + 1;
}
}
data.close();
}
void storeDetails_Pharstaff(int size5,string customer[],string medname[],int price[],int quan[])
{
  fstream data;
  data.open("Pharmacy_Customers_Details.txt",ios::app);
  for(int c=0;c<size5;c++)
  {
    data<<customer[c]<<",";
    data<<medname[c]<<",";
    data<<price[c]<<",";
    data<<quan[c];
   
    data<<endl;
      
    }
}
void readDetails_Pharstaff(int size5,string customer[],string medname[],int price[],int quan[],int &countSign2)
{
string s,s1,a,b; 
string record;
fstream data;
data.open("Pharmacy_Customers_Details.txt", ios::in);
while (!(data.eof()))
{

getline(data, record);
if((!record.empty())&& integerCheck(getField(record,3))&& integerCheck(getField(record,4)))
{
customer[countSign2] = getField(record, 1);
medname[countSign2] = getField(record, 2);
 a=getField(record, 3);
for(int i=0;a[i]!='\0';i++)
{
  s=s+a[i];
}
price[countSign2] = stoi(s);
 b=getField(record, 4);
for(int i=0;b[i]!='\0';i++)
{
  s1=s1+b[i];
}
quan[countSign2] =stoi(s1);
countSign2 = countSign2 + 1;

}
}
data.close();
}
void storeDetails_LabStaff(int size6,string cus[],string test_type[],string date1[],string price1[])
{
  fstream data;
  data.open("Laboratory_Customer_details.txt",ios::app);
  for(int c=0;c<size6;c++)
  {
    data<<cus[c]<<",";
    data<<test_type[c]<<",";
    data<<date1[c]<<",";
    data<<price1[c];
    data<<endl;
      
    }
}
void readDetails_labStaff(int size6,string cus[],string test_type[],string date1[],string price1[],int &countSign3)
{
  
string record;
fstream data;
data.open("Laboratory_Customer_details.txt", ios::in);
while (!(data.eof()))
{
getline(data, record);
if(!record.empty())
{
cus[countSign3] = getField(record, 1);
test_type[countSign3] = getField(record, 2);
date1[countSign3] = getField(record, 3);
price1[countSign3] = getField(record, 4);
countSign3 = countSign3 + 1;
}
}
data.close();
}
void store_AddPatient(int size,string patient[],string patientAge[],string patientID[])
{
   fstream data;
  data.open("AddPatient.txt",ios::app);
  for(int c=0;c<size;c++)
  {
    data<<patient[c]<<",";
    data<<patientAge[c]<<",";
    data<<patientID[c];
    data<<endl;
      
      
}
}
void read_AddPatinet(int size,string patient[],string patientAge[],string patientID[],int &countSign4)
{
 string record;
fstream data;
data.open("AddPatient.txt", ios::in);
while (!(data.eof()))
{
getline(data, record);
if(!record.empty())
{
patient[countSign4] = getField(record, 1);
patientAge[countSign4] = getField(record, 2);
patientID[countSign4] = getField(record, 3);
countSign4 = countSign4 + 1; 
}
}
data.close();
}
void store_AddDoctor(int size3,string doctor[],string DoctorID[],string doctorCategory[])
{
  fstream data;
  data.open("AddDoctor.txt",ios::app);
  for(int c=0;c<size3;c++)
  {
    data<<doctor[c]<<",";
    data<<DoctorID[c]<<",";
    data<<doctorCategory[c];
    data<<endl;
      
       
}
}
void read_AddDoctor(int size3,string doctor[],string DoctorID[],string doctorCategory[],int &countSign5)
{
string record;
fstream data;
data.open("AddDoctor.txt", ios::in);
while (!(data.eof()))
{
getline(data, record);
if(!record.empty())
{

doctor[countSign5] = getField(record, 1);
DoctorID[countSign5] = getField(record, 2);
doctorCategory[countSign5] = getField(record, 3);
countSign5 = countSign5 + 1; 
}
}
data.close();
}
void store_AddNurses(int size,string nurse[],string nurseAge[],string nurseID[],string nurseCategory[])
{
   fstream data;
  data.open("AddNurses.txt",ios::app);
  for(int c=0;c<size;c++)
  {
    data<<nurse[c]<<",";
    data<<nurseAge[c]<<",";
    data<<nurseID[c]<<",";
    data<<nurseCategory[c];
    data<<endl;
      
       
}
}
void read_AddNurses(int size,string nurse[],string nurseAge[],string nurseID[],string nurseCategory[],int &countSign6)
{
 string record;
fstream data;
data.open("AddNurses.txt", ios::in);
while (!(data.eof()))
{
getline(data, record);
if(!record.empty())
{
nurse[countSign6] = getField(record, 1);
nurseAge[countSign6] = getField(record, 2);
nurseID[countSign6] = getField(record, 3);
nurseCategory[countSign6] = getField(record, 4);
countSign6 = countSign6 + 1; 
}
}
data.close();
}
void store_AddLabStaff(string name4,string no,string role)
{
  fstream data;
  data.open("AddLaboratoryStaff.txt",ios::app);
  
  {
    data<<name4<<",";
    data<<no<<",";
    data<<role;
    data<<endl;
       
}
}
void read_AddLabStaff(string &name4,string &no,string &role)
{
   string record;
fstream data;
data.open("AddLaboratoryStaff.txt", ios::in);

{
getline(data, record);
if(!record.empty())
{
name4 = getField(record, 1);
no = getField(record, 2);
role= getField(record, 3);

}
}
data.close();
}
void store_AddPharStaff(string name5,string ID4,string role2)
{
 fstream data;
  data.open("AddPharmacyStaff.txt",ios::app);
  
  {
    data<<name5<<",";
    data<<ID4<<",";
    data<<role2;
    data<<endl;
       

}
}
void read_AddPharStaff(string &name5,string &ID4,string &role2)
{
   string record;
fstream data;
data.open("AddPharmacyStaff.txt", ios::in);

{
getline(data, record);
if(!record.empty())
{
name5 = getField(record, 1);
ID4 = getField(record, 2);
role2= getField(record, 3);
}
}
data.close();
}
void store_AddSchedule(string date)
{
   fstream data;
  data.open("AddAppointment.txt",ios::app);
  
  {
    data<<date;
    data<<endl;
    
       

}
}
void read_AddSchedule(string &date)
{
string record;
fstream data;
data.open("AddAppointment.txt", ios::in);

{
getline(data, record);
if(!record.empty())
{
date = getField(record, 1);

}
}
data.close();
}
void store_NursesSalaries(string salary[],int size)
{
   fstream data;
  data.open("AddNursesSalaries.txt",ios::app);
  for(int c=0;c<size;c++)
  {
   
    data<<salary[c];
    data<<endl;
      
       
}
}
void read_NursesSalaries(int &countSign7,string salary[])
{
  
string record;
fstream data;
data.open("AddNursesSalaries.txt", ios::in);
while (!(data.eof()))
{
getline(data, record);
if(!record.empty())
{
salary[countSign7] = getField(record, 1);
countSign7 = countSign7 + 1;
}
}
data.close();
}
bool integerCheck(string s)
{
    for(int i=0;s[i]!='\0';)
    {
        if(s[i]=='0'||s[i]=='1'||s[i]=='2'||s[i]=='3'||s[i]=='4'||s[i]=='5'||s[i]=='6'||s[i]=='7'||s[i]=='8'||s[i]=='9')
        {
            i++;
        }
        else 
        {
        return 0;
        }
    }
    return 1;
}
void updatePatient(string p1[],string symptoms[],string tests[],string medicine_name[],string treat[],int countSign1)
{
 remove("PatientDetails.txt");
  fstream data1;
  data1.open("PatientDetails.txt",ios::app);
  {
    for(int i=0;i<countSign1;i++)
    {
      data1<<p1[i]<<",";
      data1<<symptoms[i]<<",";
      data1<<tests[i]<<",";
      data1<<medicine_name[i]<<",";
      data1<<treat[i];
      data1<<endl;
    }
  }
  data1.close();
}
void updateLab_customers(string cus[],string test_type[],string date1[],string price1[],int countSign3)
{
  remove("Laboratory_Customer_details.txt");
  fstream data1;
  data1.open("Laboratory_Customer_details.txt",ios::app);
  {
    for(int i=0;i<countSign3;i++)
    {
      data1<<cus[i]<<",";
      data1<<test_type[i]<<",";
      data1<<date1[i]<<",";
      data1<<price1[i];
      data1<<endl;
    }
  }
  data1.close();
}
void updatePhar_Customers(string customer[],string medname[],int price[],int quan[],int countSign2)
{
  remove("Pharmacy_Customers_details.txt");
  fstream data1;
  data1.open("Pharmacy_Customers_details.txt",ios::app);
  {
    for(int i=0;i<countSign2;i++)
    {
      data1<<customer[i]<<",";
      data1<<medname[i]<<",";
      data1<<price[i]<<",";
      data1<<quan[i];
      data1<<endl;
    }
  }
  data1.close();
}