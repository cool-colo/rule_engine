grammar crule;
// java -cp $CLASSPATH org.antlr.v4.Tool -Dlanguage=Cpp -package rule_engine -listener -visitor -o generated/ crule.g4

// PARSER HERE
crl
    : ruleEntry* EOF
    ;

ruleEntry
    : RULE ruleName ruleDescription? salience? LR_BRACE ifScope thenScope RR_BRACE
    ;

salience
    : SALIENCE integerLiteral
    ;

ruleName
    : SIMPLENAME
    ;

ruleDescription
    : DQUOTA_STRING | SQUOTA_STRING
    ;

ifScope
    : IF  expression
    ;

thenScope
    : THEN  thenExpressionList
    ;

thenExpressionList
    : (thenExpression SEMICOLON)+
    ;

thenExpression
    : assignment
    | expressionAtom
    | ruleEntry
    ;

assignment
    : variable (ASSIGN | PLUS_ASIGN | MINUS_ASIGN | DIV_ASIGN | MUL_ASIGN | MOD_ASIGN) expression
    ;

expression
    : expression mulDivOperators expression
    | expression addMinusOperators expression
    | expression comparisonOperator expression
    | expression andLogicOperator expression
    | expression orLogicOperator expression
    | NEGATION? LR_BRACKET expression RR_BRACKET
    | expressionAtom
    | variable IN LS_BRACKET constants RS_BRACKET
    ;

mulDivOperators
    : MUL | DIV | MOD
    ;

addMinusOperators
    : PLUS | MINUS | BITAND | BITOR
    ;

comparisonOperator
    : GT | LT | GTE | LTE | EQUALS | NOTEQUALS
    ;

andLogicOperator
    : AND
    ;

orLogicOperator
    : OR
    ;

expressionAtom
    : constant
    | variable
    | functionCall
    | expressionAtom methodCall
    | expressionAtom memberVariable
    | expressionAtom arrayMapSelector
    | NEGATION expressionAtom
    ;

constants
    : constant ( ',' constant )*
    ;

constant
    : stringLiteral
    | integerLiteral
    | floatLiteral
    | booleanLiteral
    | NIL_LITERAL
    ;

variable
    : variable memberVariable
    | variable arrayMapSelector
    | SIMPLENAME
    ;

arrayMapSelector
    : LS_BRACKET expression RS_BRACKET
    ;

memberVariable
    : DOT SIMPLENAME
    ;

functionCall
    : SIMPLENAME LR_BRACKET argumentList? RR_BRACKET
    ;

methodCall
    : DOT functionCall
    ;

argumentList
    :  expression ( ',' expression )*
    ;

floatLiteral
    : decimalFloatLiteral
    | hexadecimalFloatLiteral
    ;

decimalFloatLiteral
    : MINUS? DECIMAL_FLOAT_LIT
    ;

hexadecimalFloatLiteral
    : MINUS? HEX_FLOAT_LIT
    ;

integerLiteral
    : decimalLiteral
    | hexadecimalLiteral
    | octalLiteral
    ;

decimalLiteral
    : MINUS? DEC_LIT
    ;

hexadecimalLiteral
    : MINUS? HEX_LIT
    ;

octalLiteral
    : MINUS? OCT_LIT
    ;

stringLiteral
    : DQUOTA_STRING | SQUOTA_STRING
    ;

booleanLiteral
    : TRUE | FALSE
    ;

// LEXER HERE
fragment A                  : [aA] ;
fragment B                  : [bB] ;
fragment C                  : [cC] ;
fragment D                  : [dD] ;
fragment E                  : [eE] ;
fragment F                  : [fF] ;
fragment G                  : [gG] ;
fragment H                  : [hH] ;
fragment I                  : [iI] ;
fragment J                  : [jJ] ;
fragment K                  : [kK] ;
fragment L                  : [lL] ;
fragment M                  : [mM] ;
fragment N                  : [nN] ;
fragment O                  : [oO] ;
fragment P                  : [pP] ;
fragment Q                  : [qQ] ;
fragment R                  : [rR] ;
fragment S                  : [sS] ;
fragment T                  : [tT] ;
fragment U                  : [uU] ;
fragment V                  : [vV] ;
fragment W                  : [wW] ;
fragment X                  : [xX] ;
fragment Y                  : [yY] ;
fragment Z                  : [zZ] ;


PLUS                        : '+' ;
MINUS                       : '-' ;
DIV                         : '/' ;
MUL                         : '*' ;
MOD                         : '%' ;
DOT                         : '.' ;
SEMICOLON                   : ';' ;

LR_BRACE                    : '{';
RR_BRACE                    : '}';
LR_BRACKET                  : '(';
RR_BRACKET                  : ')';
LS_BRACKET                  : '[';
RS_BRACKET                  : ']';

RULE                        : R U L E  ;
IF                          : I F ;
IN                          : I N ;
THEN                        : T H E N ;
AND                         : '&&' ;
OR                          : '||' ;
TRUE                        : T R U E ;
FALSE                       : F A L S E ;
NIL_LITERAL                 : N I L ;
NEGATION                    : '!' ;
SALIENCE                    : S A L I E N C E ;

EQUALS                      : '==' ;
ASSIGN                      : '=' ;
PLUS_ASIGN                  : '+=' ;
MINUS_ASIGN                 : '-=' ;
DIV_ASIGN                   : '/=' ;
MUL_ASIGN                   : '*=' ;
MOD_ASIGN                   : '%=' ;
GT                          : '>' ;
LT                          : '<' ;
GTE                         : '>=' ;
LTE                         : '<=' ;
NOTEQUALS                   : '!=' ;

BITAND                      : '&';
BITOR                       : '|';

SIMPLENAME                  : [a-zA-Z_] [a-zA-Z0-9_]*;

DQUOTA_STRING               : '"' ( '\\'. | '""' | ~('"'| '\\') )* '"';
SQUOTA_STRING               : '\'' ('\\'. | '\'\'' | ~('\'' | '\\'))* '\'';


DECIMAL_FLOAT_LIT           : DEC_LIT DOT DEC_LIT DECIMAL_EXPONENT?
                            | DEC_LIT DECIMAL_EXPONENT
                            | DOT DEC_LIT DECIMAL_EXPONENT?
                            ;

DECIMAL_EXPONENT            : E (PLUS|MINUS)? DEC_DIGITS;

HEX_FLOAT_LIT               : '0' X HEX_MANTISA HEX_EXPONENT
                            ;

fragment HEX_MANTISA        : HEX_DIGITS DOT HEX_DIGITS?
                            | HEX_DIGITS
                            | DOT HEX_DIGITS
                            ;

HEX_EXPONENT                : P (PLUS|MINUS)? DEC_DIGITS
                            ;

DEC_LIT                     : '0'
                            | [1-9] DEC_DIGITS?
                            ;

HEX_LIT                     : '0' X HEX_DIGITS;
OCT_LIT                     : '0' OCT_DIGITS;

fragment HEX_DIGITS         : HEX_DIGIT+;
fragment DEC_DIGITS         : DEC_DIGIT+;
fragment OCT_DIGITS         : OCT_DIGIT+;
fragment DEC_DIGIT          : [0-9];
fragment OCT_DIGIT          : [0-7];
fragment HEX_DIGIT          : [0-9a-fA-F];

// IGNORED TOKENS
SPACE                       : [ \t\r\n]+    -> skip;
COMMENT                     : '/*' .*? '*/' -> skip;
LINE_COMMENT                : '//' ~[\r\n]* -> skip;
