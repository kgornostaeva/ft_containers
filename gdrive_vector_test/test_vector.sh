#! /bin/sh

rm logs/user.output
rm logs/std.output
rm -rf logs
mkdir logs

  clang++ -Wall -Wextra -Werror -fsanitize=address -I . -I ../containers/ -I ../containers/iterators/ ft_vector_test.cpp -o logs/user_bin &&
  ./logs/user_bin > logs/user.output &&
  clang++ -Wall -Wextra -Werror -fsanitize=address std_vector_test.cpp -o logs/bin &&
  ./logs/bin > logs/std.output &&
  diff logs/user.output logs/std.output
