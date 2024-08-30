import XCTest
import SwiftTreeSitter
import TreeSitterCurry

final class TreeSitterCurryTests: XCTestCase {
    func testCanLoadGrammar() throws {
        let parser = Parser()
        let language = Language(language: tree_sitter_curry())
        XCTAssertNoThrow(try parser.setLanguage(language),
                         "Error loading Curry grammar")
    }
}
