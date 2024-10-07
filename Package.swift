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
