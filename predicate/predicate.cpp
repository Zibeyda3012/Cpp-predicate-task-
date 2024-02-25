#include<iostream>
#include<algorithm>
#include<list>

using namespace std;

class DateTime
{
	int _day;
	int _month;
	int _year;

public:
	DateTime()
	{
		_day = 1;
		_month = 1;
		_year = 2024;
	}

	DateTime(int day, int month, int year)
	{
		SetDay(day);
		SetMonth(month);
		SetYear(year);
	}

	void SetDay(int day)
	{
		if (day > 0 && day <= 31)
			this->_day = day;
		else
			throw invalid_argument("day must vary between 1 and 31");
	}

	void SetMonth(int month)
	{
		if (month > 0 && month <= 12)
			this->_month = month;

		else
			throw invalid_argument("month must vary between 1 and 12");
	}

	void SetYear(int year)
	{
		if (year >= 0) this->_year = year;
		else
			throw invalid_argument("year can not be negative");
	}

	int GetDay() { return _day; }
	int GetMonth() { return _month; }
	int GetYear() { return _year; }


};

class Debtor
{
	string FullName;
	DateTime BirthDay;
	string Phone;
	string Email;
	string Address;
	int Debt;
public:

	Debtor(string fullname, DateTime birthDay, string phone, string email, string address, int debt)
	{
		SetFullName(fullname);
		SetAddress(address);
		SetEmail(email);
		SetPhone(phone);
		SetDebt(debt);
		this->BirthDay = birthDay;
	}

	void SetFullName(string fullname)
	{
		if (fullname.size() < 1) throw invalid_argument("fullname is not given!!!");
		this->FullName = fullname;
	}

	void SetPhone(string phone)
	{
		if (phone.size() < 1) throw invalid_argument("phone number is not given!!!");
		this->Phone = phone;
	}

	void SetEmail(string email)
	{
		if (email.size() < 1) throw invalid_argument("email is not given!!!");
		this->Email = email;
	}

	void SetAddress(string address)
	{
		if (address.size() < 1) throw invalid_argument("address is not given!!!");
		this->Address = address;
	}

	void SetDebt(int debt)
	{
		if (debt < 0) throw invalid_argument("debt can not be negative!!!");
		this->Debt = debt;
	}

	string GetFullname() { return this->FullName; }
	string GetPhone() { return this->Phone; }
	string GetEmail() { return this->Email; }
	string GetAddress() { return this->Address; }
	int GetDebt() { return this->Debt; }

	int GetAge()
	{
		return (2024 - this->BirthDay.GetYear());
	}

	int GetDay()
	{
		return this->BirthDay.GetDay();
	}

	int GetMonth()
	{
		return this->BirthDay.GetMonth();
	}

	int GetYear()
	{
		return this->BirthDay.GetYear();
	}

	void print()
	{
		cout << "Fullname: " << this->FullName << endl;
		cout << "Birthday: " << this->GetDay() << "/" << this->GetMonth() << "/" << this->GetYear() << endl;
		cout << "Phone number: " << this->Phone << endl;
		cout << "Address: " << this->Address << endl;
		cout << "Email: " << this->Email << endl;
		cout << "Debt: " << this->Debt << endl;
	}

};

bool CheckAge(Debtor* d)
{
	return ((*d).GetAge() >= 26 && (*d).GetAge() <= 36);
}

bool CheckDebt(Debtor* d)
{
	return ((*d).GetDebt() < 5000);
}

bool NameAndPhoneNumber(Debtor* d)
{
	int counter = 0;
	for (size_t i = 0; i < d->GetPhone().size(); i++)
		if (d->GetPhone()[i] == '7')
			counter++;

	return (d->GetFullname().length() > 18 && counter >= 2);
}

bool compareFullname(Debtor* d1, Debtor* d2)
{
	return d1->GetFullname() > d2->GetFullname();
}

bool compareDebt(Debtor* d1, Debtor* d2)
{
	return d1->GetDebt() > d2->GetDebt();
}






int main()
{
	//Sadece 3,4,5,7,8,14,15,16 -da istenilenleri yazmaq

	/*

	3) Yashi 26 - dan 36 - ya qeder olan borclulari cixartmag

	4) Borcu 5000 - den cox olmayan borclularic cixartmag

	5) Butov adi 18 simvoldan cox olan ve telefon nomresinde 2 ve ya 2 - den cox 7 reqemi olan borclulari cixartmaq

	7) Qishda anadan olan borclulari cixardmaq

	8) Borcu, umumi borclarin orta borcunnan cox olan borclulari cixarmaq ve evvel familyaya gore sonra ise meblegin azalmagina gore sortirovka etmek

	14)Borcu en boyuk olan 5 borclunun siyahisini cixartmaq

	15)Butun borcu olanlarin borcunu cemleyib umumi borcu cixartmaq

	16)2ci dunya muharibesin gormush borclularin siyahisi cixartmaq
*/


	list<Debtor*>* debtors = new list<Debtor*>{
		new Debtor("Shirley T. Qualls", DateTime(30,3,1972), "530-662-7732", "ShirleyTQualls@teleworm.us", "3565 Eagles Nest Drive Woodland, CA 95695", 2414),
		new Debtor("Danielle W. Grier", DateTime(18,10,1953), "321-473-4178", "DanielleWGrier@rhyta.com", "1973 Stoneybrook Road Maitland, FL 32751", 3599),
		new Debtor("Connie W. Lemire", DateTime(18,6,1963), "828-321-3751", "ConnieWLemire@rhyta.com", "2432 Hannah Street Andrews, NC 28901", 1219),
		new Debtor("Coy K. Adams", DateTime(1,3,1976), "410-347-1307", "CoyKAdams@dayrep.com", "2411 Blue Spruce Lane Baltimore, MD 21202", 3784),
		new Debtor("Bernice J. Miles", DateTime(1,6,1988), "912-307-6797", "BerniceJMiles@armyspy.com", "4971 Austin Avenue Savannah, GA 31401", 4060),
		new Debtor("Bob L. Zambrano", DateTime(28,2,1990), "706-446-1649", "BobLZambrano@armyspy.com", "2031 Limer Street Augusta, GA 30901", 6628),
		new Debtor("Adam D. Bartlett", DateTime(6,5,1950), "650-693-1758", "AdamDBartlett@rhyta.com", "2737 Rardin Drive San Jose, CA 95110", 5412),
		new Debtor("Pablo M. Skinner", DateTime(26,8,1966), "630-391-2034", "PabloMSkinner@armyspy.com", "16 Fraggle Drive Hickory Hills, IL 60457", 11097),
		new Debtor("Dorothy J. Brown", DateTime(9,7,1971), "270-456-3288", "DorothyJBrown@rhyta.com", "699 Harper Street Louisville, KY 40202", 7956),
		new Debtor("Larry A. Miracle", DateTime(22,5,1988), "301-621-3318", "LarryAMiracle@jourrapide.com", "2940 Adams Avenue Columbia, MD 21044", 7150),
		new Debtor("Donna B. Maynard", DateTime(26,1,1944), "520-297-0575", "DonnaBMaynard@teleworm.us", "4821 Elk Rd Little Tucson, AZ 85704", 2910),
		new Debtor("Jessica J. Stoops", DateTime(22,4,1989), "360-366-8101", "JessicaJStoops@dayrep.com", "2527 Terra Street Custer, WA 98240", 11805),
		new Debtor("Audry M. Styles", DateTime(7,2,1937), "978-773-4802", "AudryMStyles@jourrapide.com", "151 Christie Way Marlboro, MA 01752", 1001),
		new Debtor("Violet R. Anguiano", DateTime(4,11,1958), "585-340-7888", "VioletRAnguiano@dayrep.com", "1460 Walt Nuzum Farm Road Rochester, NY 14620", 9128),
		new Debtor("Charles P. Segundo", DateTime(21,10,1970), "415-367-3341", "CharlesPSegundo@dayrep.com", "1824 Roosevelt Street Fremont, CA 94539", 5648),
		new Debtor("Paul H. Sturtz", DateTime(15,9,1944), "336-376-1732", "PaulHSturtz@dayrep.com", "759 Havanna Street Saxapahaw, NC 27340", 10437),
		new Debtor("Doris B. King", DateTime(10,10,1978), "205-231-8973", "DorisBKing@rhyta.com", "3172 Bedford Street Birmingham, AL 35203", 7230),
		new Debtor("Deanna J. Donofrio", DateTime(16,4,1983), "952-842-7576", "DeannaJDonofrio@rhyta.com", "1972 Orchard Street Bloomington, MN 55437", 515),
		new Debtor("Martin S. Malinowski", DateTime(17,1,1992), "765-599-3523", "MartinSMalinowski@dayrep.com", "3749 Capitol Avenue New Castle, IN 47362", 1816),
		new Debtor("Melissa R. Arner", DateTime(24,5,1974), "530-508-7328", "MelissaRArner@armyspy.com", "922 Hill Croft Farm Road Sacramento, CA 95814", 5037),
		new Debtor("Kelly G. Hoffman", DateTime(22,9,1969), "505-876-8935", "KellyGHoffman@armyspy.com", "4738 Chapmans Lane Grants, NM 87020", 7755),
		new Debtor("Doyle B. Short", DateTime(15,6,1986), "989-221-4363", "DoyleBShort@teleworm.us", "124 Wood Street Saginaw, MI 48607", 11657),
		new Debtor("Lorrie R. Gilmore", DateTime(23,12,1960), "724-306-7138", "LorrieRGilmore@teleworm.us", "74 Pine Street Pittsburgh, PA 15222", 9693),
		new Debtor("Lionel A. Cook", DateTime(25,12,2000), "201-627-5962", "LionelACook@jourrapide.com", "29 Goldleaf Lane Red Bank, NJ 07701", 2712),
		new Debtor("Charlene C. Burke", DateTime(18,1,1990), "484-334-9729", "CharleneCBurke@armyspy.com", "4686 Renwick Drive Philadelphia, PA 19108", 4016),
		new Debtor("Tommy M. Patton", DateTime(30,6,1981), "774-571-6481", "TommyMPatton@rhyta.com", "748 Rockford Road Westborough, MA 01581", 349),
		new Debtor("Kristin S. Bloomer", DateTime(16,6,1944), "443-652-0734", "KristinSBloomer@dayrep.com", "15 Hewes Avenue Towson, MD 21204", 9824),
		new Debtor("Daniel K. James", DateTime(10,10,1997), "801-407-4693", "DanielKJames@rhyta.com", "3052 Walton Street Salt Lake City, UT 84104", 8215),
		new Debtor("Paula D. Henry", DateTime(6,9,1976), "618-378-5307", "PaulaDHenry@rhyta.com", "3575 Eagle Street Norris City, IL 62869", 5766),
		new Debtor("Donna C. Sandoval", DateTime(13,12,1947), "540-482-5463", "DonnaCSandoval@rhyta.com", "675 Jehovah Drive Martinsville, VA 24112", 8363),
		new Debtor("Robert T. Taylor", DateTime(17,8,1932), "270-596-6442", "RobertTTaylor@armyspy.com", "2812 Rowes Lane Paducah, KY 42001", 7785),
		new Debtor("Donna W. Alamo", DateTime(9,12,1948), "978-778-2533", "DonnaWAlamo@teleworm.us", "4367 Christie Way Marlboro, MA 01752", 10030),
		new Debtor("Amy R. Parmer", DateTime(19,5,1995), "480-883-4934", "AmyRParmer@armyspy.com", "85 Elmwood Avenue Chandler, AZ 85249", 5347),
		new Debtor("Newton K. Evans", DateTime(8,9,1986), "303-207-9084", "NewtonKEvans@rhyta.com", "3552 Columbia Road Greenwood Village, CO 80111", 9838),
		new Debtor("Kathleen C. Chaney", DateTime(5,1,1949), "605-245-3513", "KathleenCChaney@rhyta.com", "316 Elsie Drive Fort Thompson, SD 57339", 1672),
		new Debtor("Manuel C. Johnson", DateTime(23,2,1957), "606-247-2659", "ManuelCJohnson@jourrapide.com", "4146 May Street Sharpsburg, KY 40374", 9195),
		new Debtor("Carla A. Creagh", DateTime(21,10,1988), "614-307-8974", "CarlaACreagh@dayrep.com", "3106 Bates Brothers Road Columbus, OH 43215", 11271),
		new Debtor("Norma M. New", DateTime(18,5,1988), "857-492-8703", "NormaMNew@jourrapide.com", "965 Metz Lane Woburn, MA 01801", 9761),
		new Debtor("Roy D. Green", DateTime(27,1,1983), "308-340-5981", "RoyDGreen@jourrapide.com", "401 Romrog Way Grand Island, NE 68801", 10771),
		new Debtor("Cristy J. Jensen", DateTime(2,10,1935), "440-626-9550", "CristyJJensen@jourrapide.com", "2177 Harley Vincent Drive Cleveland, OH 44113", 5205),
		new Debtor("Nancy J. Fergerson", DateTime(10,6,1993), "219-987-8498", "NancyJFergerson@dayrep.com", "3584 Jadewood Drive Demotte, IN 46310", 1276),
		new Debtor("Dave N. Rodriguez", DateTime(21,1,1968), "214-540-2499", "DaveNRodriguez@rhyta.com", "1890 Poco Mas Drive Dallas, TX 75247", 9132),
		new Debtor("James E. Denning", DateTime(4,5,1988), "504-289-8640", "JamesEDenning@jourrapide.com", "1444 Rose Avenue Metairie, LA 70001", 8176),
		new Debtor("Richard M. Thomas", DateTime(13,2,1973), "510-735-3359", "RichardMThomas@jourrapide.com", "4454 Green Avenue Oakland, CA 94609", 7875),
		new Debtor("Lakisha R. Forrest", DateTime(1,12,1973), "334-830-1181", "LakishaRForrest@armyspy.com", "3121 Quarry Drive Montgomery, AL 36117", 3088),
		new Debtor("Pamela H. Beauchamp", DateTime(20,10,1959), "801-559-6347", "PamelaHBeauchamp@jourrapide.com", "3239 Tori Lane Salt Lake City, UT 84104", 6588)

	};


	////task 3 (Yashi 26 - dan 36 - ya qeder olan borclulari cixartmag)

	//for (auto _debtor : *debtors)
	//{
	//	if (CheckAge(_debtor))
	//	{
	//		(*_debtor).print();
	//		cout << endl;
	//	}
	//}

	//--------------------------------------------------------------------------------------------------------------------

	////task 4 (Borcu 5000 - den cox olmayan borclularic cixartmag)

	//for (auto _debtor : *debtors)
	//{
	//	if (CheckDebt(_debtor))
	//	{
	//		(*_debtor).print();
	//		cout << endl;
	//	}
	//}

	//--------------------------------------------------------------------------------------------------------------------

	//// 	5) Butov adi 18 simvoldan cox olan ve telefon nomresinde 2 ve ya 2 - den cox 7 reqemi olan borclulari cixartmaq

	//for (auto _debtor : *debtors)
	//{
	//	if (NameAndPhoneNumber(_debtor))
	//	{
	//		_debtor->print();
	//		cout << endl;
	//	}
	//}


	//---------------------------------------------------------------------------------------------------------------------

	////7) Qishda anadan olan borclulari cixardmaq

	//[](list<Debtor*>* debtors)-> void
	//	{
	//		for (auto _debtor : *debtors)
	//			if (_debtor->GetMonth() == 1 || _debtor->GetMonth() == 2 || _debtor->GetDebt() == 12)
	//			{
	//				_debtor->print();
	//				cout << endl;
	//			}
	//		
	//	}(debtors);


	//---------------------------------------------------------------------------------------------------------------------

	////8) Borcu, umumi borclarin orta borcunnan cox olan borclulari cixarmaq ve evvel familyaya gore sonra ise meblegin azalmagina gore sortirovka etmek

	//int average_debt;

	//[&average_debt](list<Debtor*>* debtors)->void
	//	{
	//		int sum = 0;
	//		int counter = 0;
	//		for (auto _debtor : *debtors)
	//		{
	//			sum += _debtor->GetDebt();
	//			counter++;
	//		}

	//		average_debt = sum / counter;

	//	}(debtors);

	//	list<Debtor*>* newlist=new list<Debtor*>;

	//	[&newlist, average_debt](list<Debtor*>* debtors)->void
	//		{
	//			for (auto _debtor : *debtors)
	//				if (_debtor->GetDebt() > average_debt)
	//					newlist->push_back(_debtor);

	//		}(debtors);


	//		newlist->sort(compareFullname);

	//		newlist->sort(compareDebt);

	//		for (auto _debtor : *newlist)
	//		{
	//			_debtor->print();
	//			cout << endl;
	//		}

	//		for (auto _debtor : *newlist)
	//			delete _debtor;

	//		delete newlist;


//------------------------------------------------------------------------------------------------------------------------



	////14)Borcu en boyuk olan 5 borclunun siyahisini cixartmaq


	//list<Debtor*>* newlist = new list<Debtor*>;

	//debtors->sort(compareDebt);
	//int counter = 0;

	//for (auto _debtor : *debtors)
	//{
	//	if (counter == 5)
	//		break;

	//	newlist->push_back(_debtor);
	//	counter++;
	//}

	//for (auto _debtor : *newlist)
	//{
	//	_debtor->print();
	//	cout << endl;
	//}

	//for (auto _debtor : *newlist)
	//	delete _debtor;

	//delete newlist;

//-----------------------------------------------------------------------------------------------------------------------------

	////15)Butun borcu olanlarin borcunu cemleyib umumi borcu cixartmaq

	//double total_debt = 0;

	//[&total_debt](list<Debtor*>* debtors)->void
	//	{
	//		for (auto _debtor : *debtors)
	//			total_debt += _debtor->GetDebt();

	//		cout << "Total debt: " << total_debt << endl;
	//	}(debtors);



//-----------------------------------------------------------------------------------------------------------------------------

 //  //16)2ci dunya muharibesin gormush borclularin siyahisi cixartmaq


	//for (auto _debtor : *debtors)
	//	if (_debtor->GetAge() >= 80)
	//	{
	//		_debtor->print();
	//		cout << endl;
	//	}


	for (auto _debtor : *debtors)
		delete _debtor;

	delete debtors;
	











}