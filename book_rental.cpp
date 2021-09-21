#include <iostream>
#include <cmath>
#include <stdio.h>
#include <iomanip>
#include <string>
#include <fstream>
#include <limits>

using namespace std;
class Knygos
{
private:
    int knygos_nr;
    string pavadinimas_;
    int bilietas_;
    string isdavimo_data;
    string grazinimo_data;

public:
    Knygos(
        int knygos_nr = 0,
        string pavadinimas_ = "pavadinimas",
        int bilietas_ = 0,
        string isdavimo_data = "mmmm-mm-dd",
        string grazinimo_data = "mmmm-mm-dd")
    {
        this->knygos_nr = knygos_nr;
        this->pavadinimas_ = pavadinimas_;
        this->bilietas_ = bilietas_;
        this->isdavimo_data = isdavimo_data;
        this->grazinimo_data = grazinimo_data;
    }
    ~Knygos() {}
    int numeris() const
    {
        return this->knygos_nr;
    }
    string pavadinimas() const
    {
        return this->pavadinimas_;
    }
    int bilietas() const
    {
        return this->bilietas_;
    }
    string isdavimas() const
    {
        return this->isdavimo_data;
    }
    string grazinimas() const
    {
        return this->grazinimo_data;
    }
    void spausdinimas()
    {
        stringstream ss, dd, ww, gg, pp;
        ss << this->bilietas_;
        string bil_o = ss.str();

        ww << this->knygos_nr;
        string nr_o = ww.str();

        gg << this->pavadinimas_;
        string pav_o = gg.str();

        pp << this->grazinimo_data;
        string gra_o = pp.str();

        dd << this->isdavimo_data;
        string isd_o = dd.str();
        cout << setw(5) << nr_o << setw(15) << pav_o << setw(15) << bil_o << setw(15) << isd_o << setw(15) << gra_o << endl;
    }
};
void pilnas_spausdinimas(int dydis, Knygos *masyvas)
{
    cout << "   Knygos nr."
         << "   Pavadinimas "
         << "   Bilieto nr."
         << "  Isdavimo d."
         << "  Grazinimo d." << endl;
    for (int i = 0; i < dydis; i++)
    {
        cout << (i + 1) << ".  ";
        masyvas[i].spausdinimas();
    }
}
//atlaisvina vieta pasirinkitoje pozicijoje
Knygos *atlaisvinama_vieta(int dydis, Knygos *masyvas, int pozicija)
{
    Knygos *naujas;
    naujas = new Knygos[dydis + 1];
    for (int i = 0; i < dydis; i++)
    {
        naujas[i] = masyvas[i];
    }
    if (pozicija != dydis + 1)
    { //tikrinam ar nera pats galas
        for (int j = dydis; j >= pozicija; j--)
        {
            naujas[j] = masyvas[j - 1];
        }
    }
    naujas[pozicija - 1] = Knygos();
    return naujas;
}
//istrina pasirinkta informacijos eilute
Knygos *istrinimas(int dydis, Knygos *masyvas, int pozicija)
{
    Knygos *naujas;
    naujas = new Knygos[dydis - 1];
    if (pozicija != dydis)
    {
        for (int i = 0; i < pozicija; i++)
        {
            naujas[i] = masyvas[i];
        }
        for (int j = pozicija; j < dydis; j++)
        {
            naujas[j - 1] = masyvas[j];
        }
    }
    else
    {
        for (int y = 0; y < dydis - 1; y++)
        {
            naujas[y] = masyvas[y];
        }
    }
    return naujas;
}
//iesko pagal knygos numeris ir atspausdina radima
void iesko_knygos_nr(int dydis, Knygos *masyvas, int num)
{
    for (int i = 0; i < dydis; i++)
    {
        if (masyvas[i].numeris() == num)
        {
            masyvas[i].spausdinimas();
        }
    }
}
//iesko pagal knygos grazinimo data ir atspausdina radima
void iesko_grazinimas(int dydis, Knygos *masyvas, string graz)
{
    for (int i = 0; i < dydis; i++)
    {
        if (masyvas[i].grazinimas() == graz)
        {
            masyvas[i].spausdinimas();
        }
    }
}
//iesko pagal knygos grazinimo data ir atspausdina radima
void iesko_bilietas(int dydis, Knygos *masyvas, int bilie)
{
    for (int i = 0; i < dydis; i++)
    {
        if (masyvas[i].bilietas() == bilie)
        {
            masyvas[i].spausdinimas();
        }
    }
}
//surusiuoja elementus pagal knygos nr nuo didziausio iki maziausio
Knygos *rikiaviams(int dydis, Knygos *masyvas)
{
    Knygos *jonas;
    int suma;
    jonas = new Knygos[1];
    while (suma != dydis - 1)
    {
        suma = 0;
        for (int i = 0; i < dydis - 1; i++)
        {
            if (masyvas[i].numeris() < masyvas[i + 1].numeris())
            {
                jonas[0] = masyvas[i];
                masyvas[i] = masyvas[i + 1];
                masyvas[i + 1] = jonas[0];
            }
            else
            {
                suma++;
            }
        }
    }
    return masyvas;
}
//parodo pasirinkimus
void pasirinkimai()
{
    cout << endl;
    cout << "------------------------------------------" << endl;
    cout << "1. Duomenu atvaizdavimas" << endl;
    cout << "2. Duomens pridejimas" << endl;
    cout << "3. Duomens ismetimas" << endl;
    cout << "4. Paieska pagal bilieto numeri" << endl;
    cout << "5. Paieska pagal knygos numeri" << endl;
    cout << "6. Paieska pagal grazimo data" << endl;
    cout << "7. Saraso rikiavimas pagal knygos numeri" << endl;
    cout << "8. Informacijos saugojimas" << endl;
    cout << "------------------------------------------" << endl;
    cout << "Iveskite pasirinkima" << endl;
    cout << endl;
}
//patikrina ar ivedimas data
bool ar_data(string data)
{
    if (data.length() != 10)
    {
        return false;
    }
    else if (data[4] != '-' || data[7] != '-')
    {
        return false;
    }
    return true;
}
//patikrina ar ivedimas nera tiesiog raide
int gavimas_skaicius()
{
    int x = 0;
    while (!(cin >> x))
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Blogas ivedimas, kartokite: " << endl;
    }
    cout << endl;
    return x;
}
int main()
{
    ofstream i_faila;
    Knygos *masi, *laikinas;
    int dydis = 3, counter = 0;
    string i_pavadinimas, i_isdavimas, i_grazinimas, i_data;
    //------
    masi = new Knygos[dydis];
    ifstream is_failas;
    is_failas.open("informacija.txt");
    if (is_failas.fail())
    {
        cout << "Nera failo" << endl;
    }
    string f_pav, f_isd, f_gra;
    int f_num, f_bil;
    while (!is_failas.eof())
    {
        is_failas >> f_num >> f_pav >> f_bil >> f_isd >> f_gra;
        masi[counter] = Knygos(f_num, f_pav, f_bil, f_isd, f_gra);
        counter++;
    }
    is_failas.close();
    int pasirinkimas;
    while (true)
    {
        pasirinkimai();
        pasirinkimas = gavimas_skaicius();
        switch (pasirinkimas)
        {
        case 1:
            pilnas_spausdinimas(dydis, masi);
            break;
        case 2:
            int pozicija_iterpimas, i_numeris, i_bilietas;
            cout << "Kurioje vietoje norite iterpti elementa ? "
                 << "1-" << dydis + 1 << endl;
            while (true)
            {
                pozicija_iterpimas = gavimas_skaicius();
                if (pozicija_iterpimas >= 1 & pozicija_iterpimas <= dydis + 1)
                {
                    break;
                }
                cout << "Ivedimas nera ribose" << endl;
            }
            cout << "  Iveskite siuos dalykus: " << endl;
            cout << "Knygos numeri: " << endl;
            i_numeris = gavimas_skaicius();
            cout << "Knygos pavadinimas: " << endl;
            cin >> i_pavadinimas;
            cout << "Bilieto numeris: " << endl;
            i_bilietas = gavimas_skaicius();
            cout << "Isdavimo data: (mmmm-mm-dd)" << endl;
            while (true)
            {
                cin >> i_isdavimas;
                if (ar_data(i_isdavimas))
                {
                    break;
                }
                cout << "Ivedimas nera data arba nera ivestas formatu (mmmm-mm-dd)" << endl;
                cout << "Kartokite ivedima" << endl;
            }
            cout << "Grazinmo data: (mmmm-mm-dd)" << endl;
            while (true)
            {
                cin >> i_grazinimas;
                if (ar_data(i_grazinimas))
                {
                    break;
                }
                cout << "Ivedimas nera data arba nera ivestas formatu (mmmm-mm-dd)" << endl;
                cout << "Kartokite ivedima" << endl;
            }
            masi = atlaisvinama_vieta(dydis, masi, pozicija_iterpimas);
            masi[pozicija_iterpimas - 1] = Knygos(i_numeris, i_pavadinimas, i_bilietas, i_isdavimas, i_grazinimas);
            dydis++;
            break;
        case 3:
            int pozicija_istrinimas;
            cout << "Kuria eilute norite istrinti? "
                 << "1-" << dydis << endl;
            while (true)
            {
                pozicija_istrinimas = gavimas_skaicius();
                if (pozicija_istrinimas >= 1 & pozicija_istrinimas <= dydis)
                {
                    break;
                }
                cout << "Ivestas skaicius nera ribose." << endl;
            }
            masi = istrinimas(dydis, masi, pozicija_istrinimas);
            dydis--;
            break;
        case 4:
            cout << "Iveskite kokio numerio ieskote: " << endl;
            int ieskomas_bilietas;
            ieskomas_bilietas = gavimas_skaicius();
            cout << "Visi radimai: " << endl;
            iesko_bilietas(dydis, masi, ieskomas_bilietas);
            break;
        case 5:
            cout << "Iveskite kokio numerio ieskote: " << endl;
            int ieskomas_numeris;
            ieskomas_numeris = gavimas_skaicius();
            cout << "Visi radimai: " << endl;
            iesko_knygos_nr(dydis, masi, ieskomas_numeris);
            break;
        case 6:
            cout << "Iveskite data: (mmmm-mm-dd) " << endl;
            while (true)
            {
                cin >> i_data;
                if (ar_data(i_data))
                {
                    break;
                }
                cout << "Ivedimas nera data arba nera ivestas formatu (mmmm-mm-dd)" << endl;
                cout << "Kartokite ivedima" << endl;
            }
            cout << "Visi radimai: " << endl;
            iesko_grazinimas(dydis, masi, i_data);
            break;
        case 7:
            cout << "Rikiavimas ivyko " << endl;
            masi = rikiaviams(dydis, masi);
            break;
        case 8:
            i_faila.open("saugojimas.txt");
            for (int el = 0; el < dydis - 1; el++)
            {
                i_faila << masi[el].numeris() << endl;
                i_faila << masi[el].pavadinimas() << endl;
                i_faila << masi[el].bilietas() << endl;
                i_faila << masi[el].isdavimas() << endl;
                i_faila << masi[el].grazinimas() << endl;
            }
            i_faila << masi[dydis - 1].numeris() << endl;
            i_faila << masi[dydis - 1].pavadinimas() << endl;
            i_faila << masi[dydis - 1].bilietas() << endl;
            i_faila << masi[dydis - 1].isdavimas() << endl;
            i_faila << masi[dydis - 1].grazinimas();
            i_faila.close();
            cout << "Informacija issaugota sekmingai" << endl;
            break;
        default:
            cout << "Tokio pasirinkimo nera" << endl;
            break;
        }
    }

    getchar();
    getchar();
    return 0;
}
