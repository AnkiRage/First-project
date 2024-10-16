	int x ;
	srand(time(0));
	Array mas1;
	//////////// 1 пункт
	cout << "enter 5 Sizeents of MAS1 : \n";
	mas1.Scan(5);
	cout << "Array MAS1 : ";
	mas1.Print();
	//////////// 2 пункт
	cout << "\nEnter number that will change MAS1 : ";
	cin >> x;
	mas1 += x;
	cout << "New MAS1 : ";
	for (int i = 0; i < mas1.Size; i++) {
		cout << " " << mas1.Arr[i];
	}
	//////////// 3 пункт
	cout << "\nenter number of MAS2: ";
	cin >> x;
	Array mas2 = mas1;
	mas2 += x;
	cout << "Array MAS2 :";
	mas2.Print();
	//////////// 4 пункт
	cout << "\nDeleting first Sizeent of MAS2...";
	mas2.DelPos(1);
	cout << "\nNew MAS2:";
	mas2.Print();
	//////////// 5 пункт
	cout << "\nDeleting last Sizeent of MAS2 and creating MAS3...";
	Array mas3 = mas2;
	mas3.DelPos(mas3.Size);
	cout << "\nArray MAS3:";
	mas3.Print();
	//////////// 6 пункт
	cout << "\nDeleting first Sizeent of MAS1...";
	mas1.DelPos(1);
	cout << "\nNew MAS1:";
	mas1.Print();
	//////////// 7 пункт
	cout << "\nChecking if MAS1 and MAS3 are equal...";
	if (mas1 == mas3) cout << "They are"; else cout << "They are not";
	////////// 8 пункт
	cout << "\nEnter number of random Sizeent of MAS4:";
	int* B;
	cin >> x;
	B = new int[x];
	for (int i = 0; i < x; i++) B[i] = rand() % 15 + 1;
	Array mas4(B, x);
	cout << "Array MAS4 :";
	mas4.Print();
	//////////// 9 пункт
	cout << "\nMAS4: Position of MAX = " << mas4.Max() << " and MIN = " << mas4.Min();
	//////////// 10 пункт
	mas4.Sorting();
	cout << "\nSorted MAS4 :";
	mas4.Print();
	//////////// 11 пункт
	cout << "\nChecking if MAS1 and MAS4 are equal...";
	if (mas1 == mas4) cout << "They are"; else cout << "They are not";
	//////////// 12 пункт
	cout << "\nCreating MAS5 = MAS1 + MAS4 :";
	Array mas5 = mas1;
	mas5 += mas4;
	mas5.Print();
	//////////// 13 пункт
	cout << "\nAdding MAS4 to MAS3...";
	mas3 += mas4;
	cout << "\nNew MAS3:";
	mas3.Print();
	//////////// 14 пункт
	cout << "\nChecking if MAS5 and MAS3 are equal...";
	if (mas5 == mas3) cout << "They are"; else cout << "They are not";
	////////// 15 пункт
	cout << "\nCreating Array MAS6 leght of 4...";
	Array mas6(4);
	cout << "\nEnter 4 Sizeents of MAS6:\n";
	mas6.Size = 4;
	for (int i = 0; i < 4; i++) {
		cout << "Enter " << i+1 << " Sizeent: ";
		cin >> x;
		mas6.Arr[i] = x;
	}
	cout << "\nArray MAS6 :";
	mas6.Print();
	//////////// 16 пункт
	cout << "\nNow MAS4 = MAS6...";
	mas4 = mas6;
	cout << "\nMew MAS4:";
	mas4.Print();