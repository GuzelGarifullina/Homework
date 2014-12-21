
#ifndef FORMATING_INPUT_H
#define FORMATING_INPUT_H

// returns first minus or digit
char read_till_minus_or_digit (void);

void skip_spaces(char *ch); // read till find symbol(that not space)

// returns first minus or digit
char read_till_operand_or_digit (void);
int is_operand (char ch);

#endif // FORMATING_INPUT_H

