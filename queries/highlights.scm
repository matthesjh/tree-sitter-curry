; Keywords
; --------

"as" @keyword
"case" @keyword
"class" @keyword
"data" @keyword
"default" @keyword
"deriving" @keyword
"do" @keyword
"else" @keyword
"external" @keyword
"fcase" @keyword
"forall" @keyword
"free" @keyword
"hiding" @keyword
"if" @keyword
"import" @keyword
"in" @keyword
"infix" @keyword
"infixl" @keyword
"infixr" @keyword
"instance" @keyword
"let" @keyword
"module" @keyword
"newtype" @keyword
"of" @keyword
"qualified" @keyword
"then" @keyword
"type" @keyword
"where" @keyword

".." @keyword
"::" @keyword
"=" @keyword
"\" @keyword
"|" @keyword
"<-" @keyword
"->" @keyword
"@" @keyword
"~" @keyword
"=>" @keyword

; Classes
; -------

(module_identifier) @class

; Types
; -----

(type_identifier) @type
(class_identifier) @type
(type_variable_identifier) @type
(simple_type "_") @type
(simple_type_expression "_") @type
(type_constructor "()") @type.builtin
(type_constructor "[]") @type.builtin
(type_constructor "(->)") @type.builtin
(type_constructor (tuple_constructor)) @type.builtin

; Constructors
; ------------

(data_constructor_identifier) @constructor
(general_data_constructor "()") @constructor.builtin
(general_data_constructor "[]") @constructor.builtin
(general_data_constructor (tuple_constructor)) @constructor.builtin

; Functions
; ---------

(function_identifier) @function

; Properties
; ----------

(label_identifier) @property

; Variables
; ---------

(variable_identifier) @variable
(simple_pattern "_") @variable
(basic_expression "_") @variable

; Operators
; ---------

(infix_operator) @operator
":" @operator.builtin
"-" @operator.builtin

; Numbers
; -------

(int) @number
(float) @number

; Strings
; -------

(char) @string
(string) @string

; Comments
; --------

(pragma) @comment
(cpp_directive) @comment
(comment) @comment

; Punctuation
; -----------

(all_constructors) @punctuation

"(" @punctuation.bracket
")" @punctuation.bracket
"{" @punctuation.bracket
"}" @punctuation.bracket
"[" @punctuation.bracket
"]" @punctuation.bracket
"`" @punctuation.bracket

(terminal) @punctuation.delimiter
"," @punctuation.delimiter
"." @punctuation.delimiter