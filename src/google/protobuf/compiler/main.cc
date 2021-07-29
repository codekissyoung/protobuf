#include <google/protobuf/compiler/cpp/cpp_generator.h>
#include <google/protobuf/compiler/java/java_generator.h>
#include <google/protobuf/compiler/java/java_kotlin_generator.h>
#include <google/protobuf/compiler/js/js_generator.h>
#include <google/protobuf/compiler/command_line_interface.h>
#include <google/protobuf/compiler/python/python_generator.h>
#include <google/protobuf/compiler/csharp/csharp_generator.h>
#include <google/protobuf/compiler/objectivec/objectivec_generator.h>
#include <google/protobuf/compiler/php/php_generator.h>
#include <google/protobuf/compiler/ruby/ruby_generator.h>

#include <google/protobuf/port_def.inc>

namespace google {
namespace protobuf {
namespace compiler {

int ProtobufMain(int argc, char* argv[]) {

  CommandLineInterface cli;
  cli.AllowPlugins("protoc-");

  // Proto2 C++
  cpp::CppGenerator cpp_generator;
  cli.RegisterGenerator("--cpp_out", "--cpp_opt", &cpp_generator,
                        "Generate C++ header and source.");

#ifdef GOOGLE_PROTOBUF_RUNTIME_INCLUDE_BASE
  cpp_generator.set_opensource_runtime(true);
  cpp_generator.set_runtime_include_base(GOOGLE_PROTOBUF_RUNTIME_INCLUDE_BASE);
#endif

  // Proto2 Java
  java::JavaGenerator java_generator;
  cli.RegisterGenerator("--java_out", "--java_opt", &java_generator,
                        "Generate Java source file.");

  // Proto2 Kotlin
  java::KotlinGenerator kt_generator;
  cli.RegisterGenerator("--kotlin_out", "--kotlin_opt", &kt_generator,
                        "Generate Kotlin file.");


  // Proto2 Python
  python::Generator py_generator;
  cli.RegisterGenerator("--python_out", "--python_opt", &py_generator,
                        "Generate Python source file.");

  // PHP
  php::Generator php_generator;
  cli.RegisterGenerator("--php_out", "--php_opt", &php_generator,
                        "Generate PHP source file.");

  // Ruby
  ruby::Generator rb_generator;
  cli.RegisterGenerator("--ruby_out", "--ruby_opt", &rb_generator,
                        "Generate Ruby source file.");

  // CSharp
  csharp::Generator csharp_generator;
  cli.RegisterGenerator("--csharp_out", "--csharp_opt", &csharp_generator,
                        "Generate C# source file.");

  // Objective-C
  objectivec::ObjectiveCGenerator objc_generator;
  cli.RegisterGenerator("--objc_out", "--objc_opt", &objc_generator,
                        "Generate Objective-C header and source.");

  // JavaScript
  js::Generator js_generator;
  cli.RegisterGenerator("--js_out", "--js_opt", &js_generator,
                        "Generate JavaScript source.");

  return cli.Run(argc, argv);
}

}  // namespace compiler
}  // namespace protobuf
}  // namespace google

int main(int argc, char* argv[]) {
  return PROTOBUF_NAMESPACE_ID::compiler::ProtobufMain(argc, argv);
}
