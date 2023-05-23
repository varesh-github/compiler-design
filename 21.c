%{
int nchar, nword, nline;
%}
%%
\n { nline++; nchar++; }
[^ \t\n]+ { nword++, nchar += yyleng; }
. { nchar++; }
%%
int yywrap(void) {
return 1;
}
int main(int argc, char *argv[]) {
yyin = fopen(argv[1], "r");
yylex();
printf("Number of characters = %d\n", nchar);
printf("Number of words = %d\n", nword);
printf("Number of lines = %d\n", nline);
fclose(yyin);
}

Output:
G:\lex>flex count_line.l

G:\lex>gcc lex.yy.c

G:\lex>a.exe sample.c
Number of characters = 233
Number of words = 33
Number of lines = 10

G:\lex>
