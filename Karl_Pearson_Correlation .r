#
# Hackerrank Problem: https://www.hackerrank.com/challenges/correlation-and-regression-lines-6/problem
#

# X
ph <- c(15,12,8,8,7,7,7,6,5,3)

# mean of X
phm <- mean(ph)

#Y
h <- c(10,25,17,11,13,17,20,13,9,15)

# mean of Y
hm <- mean(h)

# X - mean(X)
ph_phm <- ph - phm

# Y - mean(Y)
h_hm <- h - hm

# (X -mean(X) ) ^ 2
ph_phm2 <- ph_phm ^ 2

# ( Y - mean(Y) ) ^ 2
h_hm2 <- h_hm ^ 2

# 
numr <- sum(ph_phm * h_hm)
demn <- (sum(ph_phm2) ^ 0.5 ) * (sum(h_hm2) ^ 0.5 )

# print correlation.
cat(round(numr/demn , digits=3))
