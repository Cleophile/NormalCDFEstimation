# Estimation of Gaussian CDF

Contact Information: Wang Tianmin: [Email](mailto:16307130090@fudan.edu.cn)

<img style="margin-left: auto; margin-right: auto; display: block;" src="https://render.githubusercontent.com/render/math?math=\Phi(a) = \int_{-\infty}^{a} e^{\frac{-x^2}{2}} dx">

## Hart Algorithm
The Hart Algorithm is applied for estimating CDF of one-dimensional normal distribution.
Under the estimating points listed here, accuracy of the algorithm can be more than C/C++ double accuracy.

## Gaussian Hermite for multivariate normal

### Derive Gaussian Hermite matrix

Consider n-dimensional multi-variable normal distribution. Consider the following equation:

<img style="margin-left: auto; margin-right: auto; display: block;" src="https://render.githubusercontent.com/render/math?math=F = \frac{1}{\sqrt{2\pi}} \int_{-\infty}^{+\infty} (\prod_{i=1}^n \Phi{\frac{a_i - \rho_i x}{\sqrt{1-\rho_i^2}}}) e^{-\frac{x^2}{2}} dx">

Consider:

<img style="margin-left: auto; margin-right: auto; display: block;" src="https://render.githubusercontent.com/render/math?math=\Phi{\frac{a_i - \rho_i x}{\sqrt{1-\rho_i^2}}}">

For each i, and for each x, the above equation equals to:

<img style="margin-left: auto; margin-right: auto; display: block;" src="https://render.githubusercontent.com/render/math?math=P(\rho_i x + \sqrt{1-\rho^2_i} x_i < a_i)">

Denote:

<img style="margin-left: auto; margin-right: auto; display: block;" src="https://render.githubusercontent.com/render/math?math=y_i = \rho_i x + \sqrt{1 - \rho_i^2}">
<img style="margin-left: auto; margin-right: auto; display: block;" src="https://render.githubusercontent.com/render/math?math=y_j = \rho_j x + \sqrt{1 - \rho_j^2}">

where all x are independent. Notice that:
<img style="margin-left: auto; margin-right: auto; display: block;" src="https://render.githubusercontent.com/render/math?math=E(y_i)=0">
and
<img style="margin-left: auto; margin-right: auto; display: block;" src="https://render.githubusercontent.com/render/math?math=E(y_i^2)=0">
and
<img style="margin-left: auto; margin-right: auto; display: block;" src="https://render.githubusercontent.com/render/math?math=cov(y_i, y_j) = \rho_i \rho_j">

Break
<img style="margin-left: auto; margin-right: auto; display: block;" src="https://render.githubusercontent.com/render/math?math=\rho_{ij}$ to $\rho_{ij} = \rho_i \rho_j">
for each pair of i and j:
<img style="margin-left: auto; margin-right: auto; display: block;" src="https://render.githubusercontent.com/render/math?math=F = P(y_1 < a_1 \, and \, y_2 < a_2 \, and \, ... \, and \, y_n < a_n) = F(a_1,a_2, ..., a_n)">

<img style="margin-left: auto; margin-right: auto; display: block;" src="https://render.githubusercontent.com/render/math?math=F = \frac{1}{\sqrt{\pi}} \int_{-\infty}^{+\infty} (\prod_{i=1}^n \Phi{\frac{a_i - \sqrt{2} \rho_i x}{\sqrt{1-\rho_i^2}}}) e^{-x^2} dx">

### Calculation

## Monte Carlo for multivariate normal
