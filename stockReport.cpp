#include <iostream>
#include <string>
#include <map>
#include "stock.cpp"
using namespace std;



class StockReport {

	public:
		StockReport(int initThreshold) {
			threshold = initThreshold;
		}

		void UpdateStockPrice(string name, int price) {
			Stock* newStock = new Stock(name, price);
			map<string, Stock*>::iterator it = stocks.find(newStock->GetName());
			if(it == stocks.end()) {
				//insert
				stocks.insert(make_pair(newStock->GetName(), newStock));
			} else {
				it->second->UpdateValue(price);
			}
			//todo: check pairs price difference against threshold
			for(map<string, Stock*>::iterator iter = stocks.begin(); iter != stocks.end(); ++iter) {
				string k =  iter->first;
				int v = iter->second->GetValue();
				printf("Stock %s value %d\n", k.c_str(), v);
				if(iter->second->IsPair(name)) {
					printf("Stock pair found %s %s\n", k.c_str(), name.c_str());
					Stock* found = FindStock(name);
					if(found == NULL)
						printf("Stock not found\n");
					if(abs(found->GetValue() - price) > threshold)
						printf("Threshold met\n");
				}
				iter->second->GetStockPairs();
			}
			printf("****\n");
		}

		void PairStocks(string oneStock, string twoStock) {
			map<string, Stock*>::iterator it = stocks.find(oneStock);
			if(it == stocks.end()) {
				printf("Does not contain stock %s\n", oneStock.c_str());
			} else {
				it->second->AddStockPair(twoStock);
			}
		}

		Stock* FindStock(string name) {
			for(map<string, Stock*>::iterator iter = stocks.begin(); iter != stocks.end(); ++iter) {
				string k =  iter->first;
				int v = iter->second->GetValue();
				Stock* found = new Stock(k, v);
				return found;
			}
			return NULL;
		}
	private:
		int threshold;
		map<string, Stock*> stocks;
};
