; Types

(module_identifier) @type
(type_identifier) @type

; Constructors

(constructor_identifier) @constructor

; Functions

(label (variable_identifier) @function)
(variable_identifier) @function

; Operators

(label (variable_operator) @operator)
(variable_operator) @operator

; Numbers

(int) @number

; Comments

(cpp_directive) @comment
(comment) @comment
(pragma) @comment

; Keywords

"as" @keyword
"hiding" @keyword
"import" @keyword
"infix" @keyword
"infixl" @keyword
"infixr" @keyword
"module" @keyword
"qualified" @keyword
"where" @keyword

; Punctuation

"(" @punctuation.bracket
")" @punctuation.bracket
"{" @punctuation.bracket
"}" @punctuation.bracket
"`" @punctuation.bracket
(all_constructors) @punctuation.bracket

"," @punctuation.delimiter
(terminal) @punctuation.delimiter