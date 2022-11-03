#include <iostream>
#include "stockReport.cpp"

int main() {
	std::cout<< "Hello World\n";
	StockReport* sr = new StockReport(5);
	sr->UpdateStockPrice("AA", 45);
	sr->UpdateStockPrice("BB", 45);
	sr->UpdateStockPrice("CC", 45);
	sr->UpdateStockPrice("DD", 45);
	sr->UpdateStockPrice("EE", 45);
	sr->PairStocks("AA", "BB");
	sr->PairStocks("AA", "CC");
	sr->PairStocks("BB", "CC");
	sr->PairStocks("BB", "DD");
	sr->PairStocks("DD", "EE");
	sr->PairStocks("DD", "AA");
	sr->UpdateStockPrice("BB", 51);
	return 0;
}
