package tree_sitter_curry_test

import (
	"testing"

	tree_sitter "github.com/tree-sitter/go-tree-sitter"
	tree_sitter_curry "github.com/matthesjh/tree-sitter-curry/bindings/go"
)

func TestCanLoadGrammar(t *testing.T) {
	language := tree_sitter.NewLanguage(tree_sitter_curry.Language())
	if language == nil {
		t.Errorf("Error loading Curry grammar")
	}
}
