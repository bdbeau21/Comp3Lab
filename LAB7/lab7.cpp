#undef debug

#include <iostream>
#include <string>
#include <list>
#include <map>

using namespace std;


template<typename T>
class BSTNode {

public:
	// Constructors, etc.
	BSTNode() : _data(0), _left(nullptr), _right(nullptr) {} // default constructor
	BSTNode(T data) : _left(nullptr), _right(nullptr) { _data = data; } // value constructor
	BSTNode(BSTNode&); // copy constructor
	~BSTNode(); // destructor
	BSTNode& operator= (BSTNode&); // copy assignment operator

	// ***** Your group will define/implement the insert function
	// ***** at about line 89 below...
	void insert(const T& data);

	// Accessor and mutator functions
	BSTNode<T>* getLeft() const { return _left; }
	BSTNode<T>* getRight() const { return _right; }
	T& getData() const { return _data; }
	void setData(const T& data) { _data = data; }

	// Display functions used by operator<<.
	// ***** Your group will define/implement the pre & post display functions
	// ***** at about lines 114 & 127 below...
	void inOrderDisplay(ostream&) const;
	void preOrderDisplay(ostream&) const;
	void postOrderDisplay(ostream&) const;

	// The insertion operator below uses in-order display.
	// ***** Change the implementation of this insertion operator
	// ***** in order to switch to pre- or post-order display
	friend ostream& operator<< (ostream& out, const BSTNode<T>& b)
	{
		b.preOrderDisplay(out); return out;
	}

	void listify(list<T>&) const;

private:
	T _data;
	BSTNode<T>* _left;
	BSTNode<T>* _right;

	// private "helper" functions
	void addLeft(const T& data) { _left = new BSTNode(data); }
	void addRight(const T& data) { _right = new BSTNode(data); }
};


template<typename T>
BSTNode<T>::BSTNode(BSTNode& b) {
#ifdef debug
	cout << "BSTNode copy constructor called, _data == " << _data << endl;
#endif
	_data = b._data;
	_left = _right = nullptr;
	if (b._left != nullptr) _left = new BSTNode<T>(*b._left);
	if (b._right != nullptr) _right = new BSTNode<T>(*b._right);
}


template<typename T>
BSTNode<T>::~BSTNode() {
#ifdef debug
	cout << "BSTNode destructor called, _data == " << _data << endl;
#endif
	delete _left;
	delete _right;
}


template<typename T>
BSTNode<T>& BSTNode<T>::operator= (BSTNode& b) {
#ifdef debug
	cout << "BSTNode copy assignment operator: ";
#endif
	_data = b._data;
	_left = _right = nullptr;
	if (b._left != nullptr) _left = new BSTNode<T>(*b._left);
	if (b._right != nullptr) _right = new BSTNode<T>(*b._right);
	return *this;
}


template<typename T>
void BSTNode<T>::insert(const T& data) {
	// comment out the next line when you've completed this function!
	//cout << "BSTNode<T>::insert called with data == " << data << endl;

	if (data <= _data)
	{
		if (_left != nullptr)
		{
			_left->insert(data);
		}
		else
		{
			addLeft(data);
		}
	}
	else if (data > _data)
	{
		if (_right != nullptr)
		{
			_right->insert(data);
		}
		else
		{
			addRight(data);
		}
	}
}


template<typename T>
void BSTNode<T>::inOrderDisplay(ostream& out) const {
	if (_left != nullptr) {
		_left->inOrderDisplay(out);
		out << ", ";
	}
	out << _data;
	if (_right != nullptr) {
		out << ", ";
		_right->inOrderDisplay(out);
	}
}


/**
 *  ***** Complete preOrderDisplay and postOrderDisplay below *****
 */
template<typename T>
void BSTNode<T>::preOrderDisplay(ostream& out) const {
	// comment out the next line when you've completed this function!
	//cout << "BSTNode<T>::preOrderDisplay called\n";

	out << _data;
	if (_left != nullptr) {
		out << ", ";
		_left->preOrderDisplay(out);
	}
	if (_right != nullptr) {
		out << ", ";
		_right->preOrderDisplay(out);
	}
}

template<typename T>
void BSTNode<T>::postOrderDisplay(ostream& out) const {
	// comment out the next line when you've completed this function!
	//cout << "BSTNode<T>::postOrderDisplay called\n";

	if (_left != nullptr) {
		_left->postOrderDisplay(out);
		out << ", ";
	}
	if (_right != nullptr) {
		_right->postOrderDisplay(out);
		out << ", ";
	}
	out << _data;
}

template<class T>
void BSTNode<T>::listify(list<T>& lst) const {
	if (_left != nullptr) {
		_left->listify(lst);
	}
	lst.push_back(_data);
	if (_right != nullptr) {
		_right->listify(lst);
	}
}


int main(void) {
	BSTNode<int> iroot(10);
	iroot.insert(20);
	iroot.insert(100);
	iroot.insert(200);
	iroot.insert(300);
	cout << "iroot == " << iroot << endl;

	BSTNode<string> sroot("Friday");
	sroot.insert("Monday");
	sroot.insert("Saturday");
	sroot.insert("Sunday");
	sroot.insert("Thursday");
	sroot.insert("Tuesday");
	sroot.insert("Wednesday");
	cout << "sroot == " << sroot << endl;

#ifdef debug	
	BSTNode<int> iroot2(iroot); // use copy constructor
	cout << "\nAfter copy constructor:\n";
	cout << "iroot2 == " << iroot2 << endl;

	BSTNode<int> iroot3;
	iroot3 = iroot2; // use copy assignment operator
	cout << "\nAfter copy assignment operator:\n";
	cout << "iroot3 == " << iroot3 << endl << endl;
#endif
	list<int> irootList;
	cout << "\nCreating irootList via iroot.listify\n";
	iroot.listify(irootList);

	cout << "\nirootList (forward iterator) == ";
	for (auto it = irootList.begin(); it != irootList.end(); ++it)
		cout << *it << " ";
	cout << endl;
	cout << "irootList (reverse iterator) == ";
	for (auto rit = irootList.rbegin(); rit != irootList.rend(); ++rit)
		cout << *rit << " ";
	cout << endl;
	cout << "irootList (ranged for loop) == ";
	for (auto i : irootList)
		cout << i << " ";
	cout << endl;

	list<string> srootList;
	cout << "\nCreating srootList via sroot.listify\n";
	sroot.listify(srootList);

	cout << "\nsrootList (forward iterator) == ";
	for (auto it = srootList.begin(); it != srootList.end(); ++it)
		cout << *it << " ";
	cout << endl;
	cout << "srootList (reverse iterator) == ";
	for (auto rit = srootList.rbegin(); rit != srootList.rend(); ++rit)
		cout << *rit << " ";
	cout << endl;
	cout << "srootList (ranged for loop) == ";
	for (auto s : srootList)
		cout << s << " ";
	cout << endl << endl;

	BSTNode<int> iroot4(1000);
	iroot4.insert(5000);
	iroot4.insert(4000);
	iroot4.insert(2000);
	iroot4.insert(3000);
	cout << "iroot4 == " << iroot4 << endl;
	list<int> iroot4List;
	cout << "\nCreating iroot4List via iroot4.listify\n";
	iroot4.listify(iroot4List);

	map<string, list<int>> mi;
	mi["irootList"] = irootList;
	mi["iroot4List"] = iroot4List;

	cout << "\nContents of map<string, list<int>> mi (using ranged for loops):\n";
	for (auto& kv : mi) {
		cout << kv.first << ": ";
		for (auto i : kv.second)
			cout << i << " ";
		cout << endl;
	}

	cout << "\nUsing map index operator:\nmi[\"irootList\"] == ";
	for (auto i : mi["irootList"])
		cout << i << " ";
	cout << endl;
	cout << "mi[\"iroot4List\"] == ";
	for (auto it = mi["iroot4List"].begin(); it != mi["iroot4List"].end(); ++it)
		cout << *it << " ";
	cout << endl;
	return 0;
}
