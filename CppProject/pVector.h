#pragma once
#include <vector>
#include <initializer_list>
using std::vector;

template <typename pT>
class pVector :public vector<pT>
{
private:
	void internalClear()
	{
		for (auto it = this->begin(); it != this->end(); ++it) delete *it;
	}
public:
	pVector() : vector() {}
	~pVector()
	{
		internalClear();
	}
	pVector(const pVector& pV) : vector<pT>(pV)
	{
		for (auto it = this->begin(); it != this->end(); ++it) *it = (*it)->clone();
	}
	pVector(const std::initializer_list<pT>& list)
	{
		this->reserve(list.size());
		for (auto x : list) this->push_back(x);
	}
	pVector& operator=(const pVector& pV)
	{
		if (this != &pV)
		{
			internalClear();
			vector::operator=(pV);
			for (auto it = this->begin(); it != this->end(); ++it) *it = (*it)->clone();
		}
		return *this;
	}
	void clear()
	{
		internalClear();
		vector::clear();
	}
};