module.exports = grammar({
  name: 'curry',

  rules: {
    // The production rules of the context-free grammar.
    source_file: $ => 'hello'
  }
});