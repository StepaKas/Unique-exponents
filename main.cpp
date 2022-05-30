#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>

using namespace std;


/// Minimální hodnoty by se neměly měnit
int Amin = 2;
int Bmin = 2;

/// Globani proměnné ze zadání, tychle můžou nabývat hodnot od 2 do 100
int sizeA = 100;
int sizeB = 100;




/// Paklize se x je mocninou jineho celeho cisla tak mi vrati to nejmenci mozne cislo napr kdyz x = 64 tak mi vrati 2 protoze pow(2,6) == 64, pro x = 81 mi vrati 3 protoze pow(3,4) == 81. Vracene cislo musi byt vetsi nez jedna.
/// Kdyz cislo neni mocninou jineho celeho cisla tak mi to vraci nulu.
int square_of_prime(int x);

/// Paklize int x vznikl umocnenim nejakeho integeru n tak mi tato funkce vrati cislo y kde pow(n,y) == x. Napr. kdyz x = 64 tak mi to vrati 6 protoze 2 na 6 == 64.
/// Paklize int x nevznikl umocnenim jineho integeru tak vraci 1
int square_of_prime_exponent(int x);

///Vytiskne vector integerů
void print_vec(vector <int> vec);

///Naplní vektor čísli Amim až Amax
vector <int>  fill_vec();

/// Vrací počet duplikatních čísel z vektoru. Například {1,1,1,1,5,6,8,9} vrati 3, protože jednička je tam celkem 4-krát, jednou je tam unikátně a 3-krát navíc.
int duplicates_in_vector(vector<int> vec);

/// Podle velikosti vektoru vec mi naplni vector vecXmocniny cisli napr kdyz velikost vektoru vec je 2, tak naplnim vecXmocniny cisli 2,3,..99,100,4,6,...,198,200
vector <int> naplnExponenty(vector <int> vec);

/// Tato funkce mi vrátí celkový počet duplikátů pro naše zadání
int duplikaty();

/// Tato funkce vrátí celkový počet čísel včetně duplikátů
int celkovy_pocet_cisel();


int main()
{
	while (true)
	{

	
	cout << "Zadej mi maximalni hodnotu A (3-100) a B (3-100) ";
	cin >> sizeA; 
	
	
	cin >> sizeB; cout << endl;

	///Celkový počet mocnin
	int count = celkovy_pocet_cisel();

	//Odečtu duplikatní čísla
	count -= duplikaty();

	/// vysledek vysel stejne jako je v zadani
	cout << "A je v intervalu od " << Amin << " do " << sizeA << endl;
	cout << "B je v intervalu od " << Bmin << " do " << sizeB << endl;
	cout << "Pocet unikatnich mocnin je " << count << endl << endl;
	cout << endl;
	}
}

/// Paklize se x je mocninou jineho celeho cisla tak mi vrati to nejmenci mozne cislo napr kdyz x = 64 tak mi vrati 2 protoze pow(2,6) == 64, pro x = 81 mi vrati 3 protoze pow(3,4) == 81. Vracene cislo musi byt vetsi nez jedna.
/// Kdyz cislo neni mocninou jineho celeho cisla tak mi to vraci nulu.
int square_of_prime(int x) {

	for (size_t i = Amin; i < x; i++)
	{
		int y = i;
		int j = 0;
		while (j <= sqrt(sizeA))
		{
			if (y == x) {
				return i;
			}
			y *= i;
			j++;
		}

	}
	return 0;
}

/// Paklize int x vznikl umocnenim nejakeho integeru n tak mi tato funkce vrati cislo y kde pow(n,y) == x. Napr. kdyz x = 64 tak mi to vrati 6 protoze 2 na 6 == 64.
/// Paklize int x nevznikl umocnenim jineho integeru tak vraci 1
int square_of_prime_exponent(int x) {

	for (size_t i = Amin; i < x; i++)
	{
		int y = i;
		int j = 1;
		while (j <= sqrt(sizeA))
		{
			if (y == x) {
				return j;
			}
			y *= i;
			j++;
		}

	}
	return 1;
}

///Vytiskne vector integerů
void print_vec(vector <int> vec)
{
	for (int i : vec)
	{
		cout << i << endl;
	}
}

///Naplní vektor čísli Amim až Amax
vector <int>  fill_vec()
{
	vector <int> vec;
	for (size_t i = Amin; i <= sizeA; i++)
	{
		vec.push_back(i);
	}
	//print_vec(vec);
	return vec;
}

/// Podle velikosti vektoru vec mi naplni vector vecXmocniny cisli napr kdyz velikost vektoru vec je 2, tak naplnim vecXmocniny cisli 2,3,..99,100,4,6,...,198,200
vector <int> naplnExponenty(vector <int> vec)
{
	vector <int> vecXmocniny;
	for (size_t i = 1; i <= vec.size(); i++)
	{
		for (size_t j = Bmin; j <= sizeB; j++)
		{
			vecXmocniny.push_back(j * i);
		}
	}
	return vecXmocniny;
}

/// Vrací počet duplikatních čísel z vektoru. Například {1,1,1,1,5,6,8,9} vrati 3, protože jednička je tam celkem 4-krát, jednou je tam unikátně a 3-krát navíc.
int duplicates_in_vector(vector<int> vec) {
	int result = 0;
	for (size_t i = 0; i < vec.size(); i++)
	{
		if (vec[i] == 0)
			continue;
		int buff = vec[i];
		if (i != vec.size() - 1)
			for (size_t j = i + 1; j < vec.size(); j++)
			{
				if (buff == vec[j])
				{
					result++;
					vec[j] = 0;
				}
			}
	}
	return result;
} 

/// Tato funkce mi vrátí celkový počet duplikátů pro naše zadání
int duplikaty() {
	vector <int> vec;
	int count = 0;
	vec = fill_vec();
	vector <int> podDeset;

	/// Následující for cyklus mi do vectoru podDeset přefiltruje zakladní exponety cisel, které se mi budou opakovat.
	for (int i : vec)
	{
		if (i <= sqrt(sizeA) && square_of_prime_exponent(i) == 1 && i != 1)
		{
			podDeset.push_back(i);
		}
	}

	/// Nasledující cyklus zkoumá jestli integer j na nejaký exponent k se rovná i
	for (int j : podDeset) {
		vector <int> vecBuff;
		for (int i : vec)
		{

			for (size_t k = 1; k <= sqrt(sizeA); k++)
			{
				if (i == pow(j, k)) {

					vecBuff.push_back(i);

				}
			}
		}

		vector <int> vecMocniny = naplnExponenty(vecBuff);

		int Unikatni = duplicates_in_vector(vecMocniny);
		count += Unikatni;
	}
	return count;
}

/// Tato funkce vrátí celkový počet čísel včetně duplikátů
int celkovy_pocet_cisel() {
	int count = 0;
	for (size_t a = Amin; a <= sizeA; a++)
	{
		for (size_t b = Bmin; b <= sizeB; b++)
		{
			count++;
		}
	}
	return count;
}

