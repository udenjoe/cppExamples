#include <iostream>
#include <string>
#include <vector>
#include <array>
using namespace std;

class Stock {

	public:
		Stock(string name, int value) {
			stockName = name;
      stockValue = value;
		}
		void UpdateValue(int price){
      stockValue = price;
    }
    string GetName() {
      return stockName;
    }
    int GetValue() {
      return stockValue;
    }
    void AddStockPair(string name) {
      stockPairs.push_back(name);
    }
    vector<string> GetStockPairs() {
      return stockPairs;
    }
    bool IsPair(string compare) {
      for(int i = 0; i < stockPairs.size(); i++){
        if(strcmp(compare.c_str(), stockPairs[i].c_str()) == 0)
          return true;
      }
      return false;
    }
	private:
		int stockValue;
    string stockName;
    vector<string> stockPairs;
};
