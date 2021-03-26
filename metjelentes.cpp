#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

struct Tadatok {
    string telepules;
    int ora = 0 ;
    int perc = 0;
    string irany;
    int erosseg = 0;
    int hom = 0;
    string szelerosseg;
};


int main()
{
    string temp;
    int db = 0;
    ifstream fajl ("tavirathu13.txt");
    while (!fajl.eof()) {getline(fajl,temp);db++;}
    db--;
    fajl.close();

    ifstream be("tavirathu13.txt");
    int i=0;
    Tadatok adat[db];
    string ora_s[db];
    string perc_s[db];
    string erosseg_s[db];
    string hom_s[db];
    string varosok[db];
    int varos_szam = 0;

    for (i=0;i<db;i++)
    {
    getline (be,temp);
    adat[i].telepules = temp.substr(0,2); // kész , string

    adat[i].szelerosseg = temp.substr(8,5); // kész , string

    adat[i].irany = temp.substr(8,3); // kész , string

    ora_s[i] = temp.substr(3,2); // kész , int
    stringstream ora_toint(ora_s[i]);
    ora_toint >> adat[i].ora;

    perc_s[i] = temp.substr(5,2); //kész , int
    stringstream perc_toint(perc_s[i]);
    perc_toint >> adat[i].perc;

    erosseg_s[i] = temp.substr(11,2); //kész , int
    stringstream erosseg_toint(erosseg_s[i]);
    erosseg_toint >> adat[i].erosseg;

    hom_s[i] = temp.substr(14,2); //kész , int
    stringstream hom_toint(hom_s[i]);
    hom_toint >> adat[i].hom;

    int j = 0;
    int szaml = 0;
    for (j=0;j<varos_szam;j++){
    if (adat[i].telepules == varosok[j]){szaml++;}}
    if (szaml == 0){varosok[varos_szam++] = adat[i].telepules;}}
    be.close();

    string telepules;
    int utolso_ora = 0;
    int utolso_perc = 0;

    cout<<"2. feladat"<<endl;
    cout<<"Adja meg egy telepules kodjat! Telepules: ";
    cin >> telepules;
    for(i=0;i<db;i++){
    if(adat[i].telepules == telepules and adat[i].ora >=utolso_ora and adat[i].perc >=utolso_perc) { utolso_ora = adat[i].ora; utolso_perc = adat[i].perc;}}
    cout<<"Az utolso meresi adat a megadott telepulesrol "<<utolso_ora<<":"<<utolso_perc<<"-kor erkezett."<<endl;

    cout<<"3. feladat"<<endl;
    int leg_magas_hom = 0;
    int leg_magas_ora = 0;
    int leg_magas_perc = 0;
    string leg_magas_varos;
    for (i=0;i<db;i++){
    if (adat[i].hom > leg_magas_hom) { leg_magas_hom = adat[i].hom; leg_magas_ora = adat[i].ora; leg_magas_perc = adat[i].perc; leg_magas_varos = adat[i].telepules;}}
    int leg_alacsony_hom = leg_magas_hom;
    int leg_alacsony_ora = 0;
    int leg_alacsony_perc = 0;
    string leg_alacsony_varos;
    for (i=0;i<db;i++){
    if(adat[i].hom < leg_alacsony_hom) {leg_alacsony_hom = adat[i].hom; leg_alacsony_ora = adat[i].ora; leg_alacsony_perc = adat[i].perc; leg_alacsony_varos = adat[i].telepules;}}
    cout<<"A legalacsonyabb homerseklet: "<<leg_alacsony_varos<<" "<<leg_alacsony_ora<<":"<<leg_alacsony_perc<<" "<<leg_alacsony_hom<<" fok."<<endl;
    cout<<"A legmagasabb homerseklet: "<<leg_magas_varos<<" "<<leg_magas_ora<<":"<<leg_magas_perc<<" "<<leg_magas_hom<<" fok."<<endl;

    cout<<"4. feladat"<<endl;
    int nem_volt = 0;
    for (i=0;i<db;i++){
    if (adat[i].szelerosseg == "00000"){cout<<adat[i].telepules<<" "<<(adat[i].ora<9?"0":"")<<adat[i].ora<<":"<<(adat[i].perc<9?"0":"")<<adat[i].perc<<endl;nem_volt ++;}}
    if (nem_volt == 0)
        cout<<"Nem volt szelcsend a meresek idejen"<<endl;

    cout<<"5. feladat"<<endl;
    int idoszam[4];
    float idoosszeg[4];
    int j = 0;
    int smin;
    int smax;
    for (i=0;i<varos_szam;i++){
        smin = 200;
        smax = 0;
        cout<<varosok[i]<<" ";
        for (j=0;j<4;j++) {idoszam[j] = 0;idoosszeg[j] = 0;}
        for (j=0;j<db;j++){
             if (adat[j].telepules == varosok[i]) {
             if (smin > adat[j].hom) {smin = adat[j].hom;}
             if (smax < adat[j].hom) {smax=adat[j].hom;}
             if (adat[j].ora == 1) { idoszam[0]++; idoosszeg[0] += adat[j].hom;}
             if (adat[j].ora == 7) {idoszam[1]++; idoosszeg[1] += adat[j].hom;}
             if (adat[j].ora == 13) { idoszam[2]++; idoosszeg[2] += adat[j].hom;}
             if (adat[j].ora == 19) { idoszam[3]++; idoosszeg[3] += adat[j].hom; }}}
             if ((idoszam[0]==0) || (idoszam[1]==0) || (idoszam[2]==0) || (idoszam[3]==0)) {cout<<"NA; ";}
             else{ float x = idoosszeg[0]+idoosszeg[1]+idoosszeg[2]+idoosszeg[3]; x /= (idoszam[0]+idoszam[1]+idoszam[2]+idoszam[3]); cout<<(int)(x+0.5)<<"; ";}
    cout<< "Homerseklet-ingadozas: "<<smax-smin<<endl;}

    cout<<"6. feladat"<<endl;
    for (i=0;i<varos_szam;i++){
        string s = varosok[i] + ".txt";
        ofstream f (s.c_str());
        f<<varosok[i]<<endl;
        for (j=0;j<db;j++){
            if (adat[j].telepules == varosok[i]){
                f<<(adat[j].ora<10?"0":"")<<adat[j].ora<<":"<<(adat[j].perc<10?"0":"")<<adat[j].perc<<" ";
                for (int k = 0;k<adat[j].erosseg;k++) {f<<"#";}f<<endl;}}
    f.close();}
    cout<<"A fajlok elkeszultek";
    return 0;
}
