
#include <iostream>
#include <Eigen/Dense>
#include <Eigen/SVD>

double condA(const Eigen::MatrixXd& A)
{
  Eigen::JacobiSVD<Eigen::MatrixXd> svd(A);
  Eigen::VectorXd singularValuesA = svd.singularValues();
  return singularValuesA.maxCoeff() / singularValuesA.minCoeff();
}

int main(int argc, char **argv) 
{
  const double tol = 1.0e-15;
  unsigned int n = 3;

  Eigen::MatrixXd B = Eigen::MatrixXd::Random(n, n);
  if (abs(B.determinant()) < tol)
    return -1;
  Eigen::MatrixXd A = B.transpose() * B;
  
  Eigen::VectorXd x_ex = Eigen::VectorXd::Ones(n);
  Eigen::VectorXd b = A * x_ex;

  Eigen::VectorXd x = Eigen::VectorXd::Zero(n); // x_0
  Eigen::VectorXd res = b - A * x;              // r_0 = b - A * x_0
  Eigen::VectorXd p = res;                      // p_0 = r_0
  
  double res_norm_0 = res.norm();

  const unsigned int it_max = 10000;
  unsigned int it = 0;
  const double res_tol = 1.0e-12;

  std::cout.precision(2);
  std::cout << std::scientific << "Matrix Cond: " << condA(A) << std::endl;
 
  while (it < it_max && res.norm() > res_tol * res_norm_0)
  {
    Eigen::VectorXd Ap = A * p;
    double p_Ap = p.dot(Ap); // p_k^T A p_k

    // calcolo a_k
    double alpha_k = p.dot(res) / p_Ap;

    // aggiornamento suluzione
    x = x + alpha_k * p;

  // aggiornamento residuo
    Eigen::VectorXd res_next = b - A * x;

    double beta_k = p.dot(A * res_next) / p_Ap;
 
    p = res_next - beta_k * p;

    res = res_next;
    it++;
  }

  const auto err_rel = (x_ex.norm() == 0.0) ? (x - x_ex).norm() :
                                              (x - x_ex).norm() / x_ex.norm();

  std::cout.precision(4);
  std::cout << std::scientific << "Iterazioni completate: " << it << "/" << it_max << std::endl;
  std::cout << std::scientific << "Rapporto res / res_tol: " << res.norm() / res_norm_0 << " / " << res_tol << std::endl;
  std::cout << std::scientific << "Errore relativo: " << err_rel << std::endl;
  std::cout << "Soluzione calcolata:\n" << x << std::endl;

  return 0;
}
