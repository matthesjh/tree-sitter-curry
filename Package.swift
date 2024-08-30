// swift-tools-version:5.3
import PackageDescription

let package = Package(
    name: "TreeSitterCurry",
    products: [
        .library(name: "TreeSitterCurry", targets: ["TreeSitterCurry"]),
    ],
    dependencies: [
        .package(url: "https://github.com/ChimeHQ/SwiftTreeSitter", from: "0.8.0"),
    ],
    targets: [
        .target(
            name: "TreeSitterCurry",
            dependencies: [],
            path: ".",
            exclude: [
                "Cargo.toml",
                "Makefile",
                "binding.gyp",
                "bindings/c",
                "bindings/go",
                "bindings/node",
                "bindings/python",
                "bindings/rust",
                "prebuilds",
                "go.mod",
                "grammar.js",
                "package.json",
                "package-lock.json",
                "pyproject.toml",
                "setup.py",
                "test",
                "examples",
                ".editorconfig",
                ".eslintrc.json",
                ".github",
                ".gitignore",
                ".gitattributes",
                ".gitmodules",
            ],
            sources: [
                "src/parser.c",
                "src/scanner.c",
            ],
            resources: [
                .copy("queries")
            ],
            publicHeadersPath: "bindings/swift",
            cSettings: [.headerSearchPath("src")]
        ),
        .testTarget(
            name: "TreeSitterCurryTests",
            dependencies: [
                "SwiftTreeSitter",
                "TreeSitterCurry",
            ],
            path: "bindings/swift/TreeSitterCurryTests"
        )
    ],
    cLanguageStandard: .c11
)
