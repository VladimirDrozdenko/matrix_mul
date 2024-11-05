#include <exception>
#include <iostream>
#include <vector>


void multiply(const std::vector<std::vector<double> >& a,
			  const std::vector<std::vector<double> >& b,
			  std::vector<std::vector<double> >& res) {

	const size_t arows = a.size();
	const size_t acols = a[0].size();
	const size_t brows = b.size();
	const size_t bcols = b[0].size();

	if (acols != brows) {
		throw std::runtime_error("Provided matrixes cannot be multiplied A.Cols must be equal to B.Rows.");
	}

	for (size_t cr = 0; cr < arows; ++cr) {
		std::vector<double> res_row;
		for (size_t cc = 0; cc < bcols; ++cc) {
			double val = 0;
			for (size_t i = 0; i < acols; ++i) {
				val += a[cr][i] * b[i][cc];
			}
			res_row.push_back(val);
		}
		res.push_back(res_row);
	}
}

int main() {
	std::vector<std::vector<double>> ina = {
		{1, 2, 1},
		{4, 5, 2},
		{7, 4, 2}
	};

	std::vector<std::vector<double>> inb = {
		{1, 2},
		{2, 2},
		{3, 0}
	};

	std::vector<std::vector<double>> res;

	try {
		multiply(ina, inb, res);
	}
	catch (const std::runtime_error& ex) {
		std::cerr << "Exception: " << ex.what() << std::endl;
		return 1;
	}

	for (size_t i = 0; i < res.size(); ++i) {
		for (size_t j = 0; j < res[i].size(); ++j) {
			std::cout << res[i][j] << " ";
		}
		std::cout << std::endl;
	}
}
