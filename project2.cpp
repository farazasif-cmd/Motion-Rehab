//Logic Loopers
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
// ARRAYS
const int SZ=100;   
string names[SZ], diseases[SZ];
int ages[SZ];
string t_name[SZ], therapy[SZ], date[100], timee[SZ];
int totalP = 0;
int totalTherapy = 0;
// FUNCTIONS
void savePatients();
void addPatient();
void viewPatients();
void saveTherapy();
void scheduleTherapy();
void viewTherapy();
void generateBill();
void suggestTreatment();
int main()
{
    int choice;
    do 
    {
        cout << "\n--- Mind & Motion Rehab System ---" << endl;
        cout << "1. Add Patient\n";
        cout << "2. View Patients\n";
        cout << "3. Schedule Therapy\n";
        cout << "4. View Therapy\n";
        cout << "5. Generate Bill\n";
        cout << "6. Suggest Treatment (Addiction)\n";
        cout << "7. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore();   
        if (choice == 1)
        {
            addPatient();
        }
        else if (choice == 2) 
        {
            viewPatients();
        }
        else if (choice == 3)
        {
            scheduleTherapy();
        }
        else if (choice == 4)
        {
            viewTherapy();
        }
        else if (choice == 5)
        {
            generateBill();
        }
        else if (choice == 6) 
        {
            suggestTreatment();
        }
       else if (choice == 7)
        {
            break;
        }
    }while(choice<=7);

    return 0;
}

void savePatients() 
{
    ofstream fout("patients.txt");
    for (int i = 0; i < totalP; i++) 
    {
        fout<< names[i] << "|";
        fout<< ages[i] << "|";
        fout<< diseases[i] << endl;
    }
    fout.close();
}
void addPatient() 
{
    cout << "Enter full name: ";
    getline(cin, names[totalP]);
    cout << "Enter age: ";
    cin >> ages[totalP];
    cin.ignore();
    cout << "Enter Addiction: ";
    getline(cin, diseases[totalP]);
    totalP++;
    savePatients();
    cout << "Patient added!\n";
}
void viewPatients() 
{
    cout << "\n--- Patients ---\n";
    if (totalP == 0) 
    {
        cout << "No patients found!\n";
        return;
    }
    for (int i = 0; i < totalP; i++) 
    {
        cout << i + 1 << ". ";
        cout<< names[i] << " | ";
        cout<< ages[i] << " | ";
        cout<< diseases[i] << endl;
    }
    cout<<"\n ---All  Patients Are Displayed_----\n";
}
void saveTherapy()
 {
    ofstream fout("therapy.txt");
    for (int i = 0; i < totalTherapy; i++) 
    {
        fout << t_name[i] << "|";
        fout<< therapy[i] << "|";
        fout<< date[i] << "|";
        fout<< timee[i] << endl;
    }
    fout.close();
}
void scheduleTherapy() 
{
    cout << "Enter patient full name: ";
    getline(cin, t_name[totalTherapy]);
    cout << "Enter therapy type: ";
    cout<<"\n[Cognitive-Behavioral Therapy (CBT)/Counseling/Speech]";
    getline(cin, therapy[totalTherapy]);
    cout << "Enter date: ";
    getline(cin, date[totalTherapy]);
    cout << "Enter time: ";
    getline(cin, timee[totalTherapy]);
    totalTherapy++;
    saveTherapy();
    cout << "Therapy scheduled!\n";
}
void viewTherapy() 
{
    cout << "\n--- Therapy Schedule ---\n";
    for (int i = 0; i < totalTherapy; i++) {
        cout << t_name[i] << " | ";
        cout<< therapy[i] << " | ";
        cout<< date[i] << " | ";
        cout<< timee[i] << endl;
    }
}
void generateBill() 
{
    string name;
    int therapy=0;
    int sessions = 0, cost = 0,days=0; 
    cin.ignore(); 
    cout << "Enter patient full name: ";
    getline(cin, name);
    cout << "Enter number of days stayed (Per Day/-2000): ";
    cin >> days;
    cout << "Enter number of sessions: ";
    cin >> sessions;
    cout << "\nEnter therapy type:\n0-CBT = 3500\n1-Counseling = 1500\n2-Speech = 2000\nEnter Choice(0-2): ";
    cin >> therapy; 
    if (therapy == 0)
    { 
        cost = 3500; 
    } else if ( therapy == 1) 
    { 
        cost = 1500; 
    } else if (therapy == 2) 
    { 
        cost = 2000; 
    } 
    else
    { 
        cost = 0; 
        cout << "Invalid therapy type! Cost set to 0." << endl;
    } 
    cout << "Therapy Charges: " << sessions * cost<< endl;
    cout << "Stay Charges: " << days * 2000 << endl;
    cout << "\n--- BILL ----\n"; 
    cout << "Patient: " << name << endl; 
    cout << "Sessions: " << sessions << endl; 
    cout << "Total Bill: " << sessions * cost + days * 2000 << endl; 

}
void suggestTreatment() 
{
   int symptom;
    
    cout << "Enter main symptom of addiction(0-3):\n";
    cout << "0-anxiety\n1-insomnia \n2-cravings \n3-depression): ";
    cin>>symptom;
    cout << "\n----SUGGESTED TREATMENT ---\n";
    //checking both exact lowercase and exact uppercase literals
    if (symptom == 0)
     {
        cout << "Suggested Medication: Anti-anxiety drugs (e.g., Diazepam)\n";
        cout << "Therapy: Cognitive Behavioral Therapy (CBT)\n";
    } 
    else if (symptom == 1) 
    {
        cout << "Suggested Medication: Sleep aids (e.g., Melatonin)\n";
        cout << "Therapy: Sleep therapy / relaxation techniques\n";
    } 
    else if (symptom == 2) 
    {
        cout << "Suggested Medication: Naltrexone (for addiction control)\n";
        cout << "Therapy: Behavioral therapy\n";
    } 
    else if (symptom == 3)
     {
        cout << "Suggested Medication: Antidepressants (e.g., SSRIs)\n";
        cout << "Therapy: Counseling / psychotherapy\n";
    } 
    else
     {
        cout << "No exact match found.\n";
        cout << "General Advice: Consult a rehabilitation specialist.\n";
    }
}