#include <iostream>
#include <string>
#include <fstream>
#include<List>
using namespace std;

void populate_hash(string filename, HashMap<string> &hash)
{
	ifstream file;
	file.open(filename);
	if (!file.is_open())
	{
		cout << "  error while opening file " << endl;
	}
	else
	{
		int num;
		int id;
		string value;
		file >> num;

		for (int i = 0; i < num; i++)
		{
			file >> id;
			file >> value;
			hash.insert(id, value);
		}
	}
}

template <class v>
struct HashItem
{
	int key;
	v value;
	short status;
	list <v> ll; //STL list

public:
	HashItem()
	{
		key = 0;
		status = 0;
	}
	HashItem operator =(HashItem& hash)
	{
		key = hash->key;
		value = hash->value;
		status = hash->status;
		ll = hash->ll;
		return *this;
	}
};


template <class v>
class HashMap
{
private:
	HashItem <v> *hashArray;
	int capacity;
	int currentElements;
	virtual int getNextCandidateIndexIndex(int key, int i)
	{
		if (hashArray[i]->status() == 0)
		{
			return i;
		}
		else
		{
			while (hashArray[i]->status() != 0)
			{
				if (i == capacity - 1)
				{
					i = 0;
				}
				i++;
			}
			return i;
		}
	}

public:

	HashMap()
	{
		hashArray = new hashitem<v>[10];
		capacity = 10;
		currentElement = 0;
	}

	HashMap(int const capacity)
	{
		if (capacity >= 1)
		{
			hashArray = new hashitem<v>[capacity];
			this->capacity = capacity;
			currentElement = 0;
		}
	}

	void insert(int const key, v const value)
	{
		int index = key % capacity;

		index = getNextCandidateIndex(key, index);

		hashArray[index]->value = value;
		hashArray[index]->status = 2;
		hashArray[index]->key = key;
		currentElement++;

		float current = currentElement;
		float capacityx = capacity;
		float temp = current / capacityx;
		if (temp >= 0.75)
		{
			doubleCapacity();
		}
	}
	void doubleCapacity()
	{
		int capacityx = capacity * 2;

		hashitem<v>* array1 = new hashitem<v>[capacityx];


		for (int i = 0; i < capacity; i++)
		{
			if (hashArray[i]->status() == 2)
			{

				int index = hashArray[i]->key % capacityx;

				index = getNextCandidateIndex(hashArray[i]->key, index);

				array1[index]->value = hashArray[i]->value;
				array1[index]->status = 2;
				array1[index]->key = hashArray[i]->key;
			}
		}
		capacity = capacityx;
		hashArray = array1;
	}

	bool delete_key(int const key)
	{
		bool flag = false;
		int index = key % capacity;
		int num;
		if (index == capacity - 1)
		{
			num = 0;
		}
		else
		{
			num = index;
			num++;
		}
		if (hashArray[index]->key == key)
		{
			hashArray[index]->status = 1;
			flag = true;
		}
		else
		{
			while (num != index)
			{
				if (hashArray[num]->key == key)
				{
					hashArray[num]->status = 1;
					flag = true;
					break;
				}
				else
				{
					if (num == capacity - 1)
					{
						num = 0;
					}
					else
					{
						num++;
					}
				}
			}
		}
		return flag;
	}
	void Print()
	{
		for (int i = 0; i < capacity; i++)
		{
			cout << i << " " << hashArray[i]->key << "  " << hashArray[i]->status << "  " << hashArray[i]->value << endl;
		}
	}

	~HashMap()
	{
		for (int i = 0; i <= 10;i++)
		delete hashArray[i];
	}
};


template<class v>
class QHashMap :public HashMap
{
private:
	HashItem <v> *QhashArray;
	int capacity;
	int currentElements;
	virtual int getNextCandidateIndexIndex(int key, int i)
	{
		if (QhashArray[i]->status() == 0)
		{
			return i;
		}
		else
		{
			while (QhashArray[i]->status() != 0)
			{
				if (i == capacity - 1)
				{
					i = 0;
				}
				i++;
			}
			return i;
		}
	}

public:

	QHashMap()
	{
		QhashArray = new hashitem<v>[10];
		capacity = 10;
		currentElement = 0;
	}

	QHashMap(int const capacity)
	{
		if (capacity >= 1)
		{
			QhashArray = new hashitem<v>[capacity];
			this->capacity = capacity;
			currentElement = 0;
		}
	}

	void insert(int const key, v const value)
	{
		int index = key % capacity;

		index = getNextCandidateIndex(key, index);

		QhashArray[index]->value = value;
		QhashArray[index]->status = 2;
		QhashArray[index]->key = key;
		currentElement++;

		float current = currentElement;
		float capacityx = capacity;
		float temp = current / capacityx;
		if (temp >= 0.75)
		{
			doubleCapacity();
		}
	}
	void doubleCapacity()
	{
		int capacityx = capacity * 2;

		hashitem<v>* Qarray1 = new hashitem<v>[capacityx];


		for (int i = 0; i < capacity; i++)
		{
			if (QhashArray[i]->status() == 2)
			{

				int index = QhashArray[i]->key % capacityx;

				index = getNextCandidateIndex(QhashArray[i]->key, index);

				Qarray1[index]->value = QhashArray[i]->value;
				Qarray1[index]->status = 2;
				Qarray1[index]->key = QhashArray[i]->key;
			}
		}
		capacity = capacityx;
		QhashArray = Qarray1;
	}

	bool delete_key(int const key)
	{
		bool flag = false;
		int index = key % capacity;
		int num;
		if (index == capacity - 1)
		{
			num = 0;
		}
		else
		{
			num = index;
			num++;
		}
		if (QhashArray[index]->key == key)
		{
			QhashArray[index]->status = 1;
			flag = true;
		}
		else
		{
			while (num != index)
			{
				if (QhashArray[num]->key == key)
				{
					QhashArray[num]->status = 1;
					flag = true;
					break;
				}
				else
				{
					if (num == capacity - 1)
					{
						num = 0;
					}
					else
					{
						num++;
					}
				}
			}
		}
		return flag;
	}
	void Print()
	{
		for (int i = 0; i < capacity; i++)
		{
			cout << i << " " << QhashArray[i]->key << "  " << QhashArray[i]->status << "  " << QhashArray[i]->value << endl;
		}
	}

	~QHashMap()
	{
		for (int i = 0; i <= 10; i++)
			delete QhashArray[i];
	}
};

template<class v>
class DHashMap : public HashMap
{
private:
	HashItem <v> *DhashArray;
	int capacity;
	int currentElements;
	virtual int getNextCandidateIndexIndex(int key, int i)
	{
		if (DhashArray[i]->status() == 0)
		{
			return i;
		}
		else
		{
			while (DhashArray[i]->status() != 0)
			{
				if (i == capacity - 1)
				{
					i = 0;
				}
				i++;
			}
			return i;
		}
	}

public:

	DHashMap()
	{
		DhashArray = new hashitem<v>[10];
		capacity = 10;
		currentElement = 0;
	}

	DHashMap(int const capacity)
	{
		if (capacity >= 1)
		{
			DhashArray = new hashitem<v>[capacity];
			this->capacity = capacity;
			currentElement = 0;
		}
	}

	void insert(int const key, v const value)
	{
		int index = key % capacity;

		index = getNextCandidateIndex(key, index);

		DhashArray[index]->value = value;
		DhashArray[index]->status = 2;
		DhashArray[index]->key = key;
		currentElement++;

		float current = currentElement;
		float capacityx = capacity;
		float temp = current / capacityx;
		if (temp >= 0.75)
		{
			doubleCapacity();
		}
	}
	void doubleCapacity()
	{
		int capacityx = capacity * 2;

		hashitem<v>* Darray1 = new hashitem<v>[capacityx];


		for (int i = 0; i < capacity; i++)
		{
			if (DhashArray[i]->status() == 2)
			{

				int index = DhashArray[i]->key % capacityx;

				index = getNextCandidateIndex(DhashArray[i]->key, index);

				Darray1[index]->value = DhashArray[i]->value;
				Darray1[index]->status = 2;
				Darray1[index]->key = DhashArray[i]->key;
			}
		}
		capacity = capacityx;
		DhashArray = Darray1;
	}

	bool delete_key(int const key)
	{
		bool flag = false;
		int index = key % capacity;
		int num;
		if (index == capacity - 1)
		{
			num = 0;
		}
		else
		{
			num = index;
			num++;
		}
		if (DhashArray[index]->key == key)
		{
			DhashArray[index]->status = 1;
			flag = true;
		}
		else
		{
			while (num != index)
			{
				if (DhashArray[num]->key == key)
				{
					DhashArray[num]->status = 1;
					flag = true;
					break;
				}
				else
				{
					if (num == capacity - 1)
					{
						num = 0;
					}
					else
					{
						num++;
					}
				}
			}
		}
		return flag;
	}
	void Print()
	{
		for (int i = 0; i < capacity; i++)
		{
			cout << i << " " << DhashArray[i]->key << "  " << DhashArray[i]->status << "  " << DhashArray[i]->value << endl;
		}
	}

	~DHashMap()
	{
		for (int i = 0; i <= 10; i++)
			delete DhashArray[i];
	}
};



int main()
{
	HashMap <string> *map;
	map = new HashMap <string> ; // map=new QHashMap&lt;string&gt;;you will use polymorphism to runfor all the classes.

	populateHash("students.txt" , map);
	cout<< *map->get(9);
	map->deleteKey(9);
	assert(map->get(9) == nullptr);
	delete map;
	
	map = new QHashMap<string>;
	populateHash("students.txt" , map);
	cout<< *map->get(98);
	map->deleteKey(98);
	assert(map->get(98) == nullptr);
	delete map;

	map = new DHashMap<string>;
	populateHash("students.txt" , map);
	cout<< *map->get(101);
	map->deleteKey(101);
	assert(map->get(101) == nullptr);
	delete map;

	return 0;
}