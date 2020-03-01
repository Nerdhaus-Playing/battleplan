from conans import ConanFile, CMake, tools

def getVersion():
   git = tools.Git()
   try:
      parts = git.run("describe --tags").split("-")
      try:
         return parts[0]+"."+parts[1]
      except:
         return parts[0]
   except:
      return "0.0.0"
   return "0.0.0"

class ArbitraryCommandLineToolConan(ConanFile):
   scm = {
      "type": "git",
      "url": "auto",
      "revision": "auto"
   }
   name = "aclt"
   version = getVersion()
   #license = "<Put the package license here>"
   #url = "<Package recipe repository url here, for issues about the package>"
   description = "A Command line tool for arbitrary environments"
   settings = "os", "compiler", "build_type", "arch"
   options = {"shared": [True, False], "with_tests": [True, False], "with_demo": [True, False]}
   default_options = {"shared": False, "with_tests": False, "with_demo": False}
   generators = "cmake"

   def build_requirements(self):
      if self.options.with_tests == True :
         self.build_requires("gtest/1.10.0@nerdhaus-mirror/stable")
      self.build_requires("boost/1.71.0@conan/stable")
      self.build_requires( "sfml/2.5.1@bincrafters/stable")
      self.options["sfml"].shared = True
      self.options["sfml"].graphics = True
      self.options["sfml"].window = True

   def build(self):
      cmake = CMake(self)
      cmake.definitions["BUILD_WITH_TESTS"] = self.options.with_tests
      cmake.definitions["BUILD_WITH_DEMO"] = self.options.with_demo
      cmake.configure()
      cmake.build()

   def package(self):
      cmake = CMake(self)
      cmake.configure()
      cmake.install()

   def deploy(self):
      self.copy("*")