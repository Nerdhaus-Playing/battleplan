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
   name = "battleplan"
   version = getVersion()
   #license = "<Put the package license here>"
   #url = "<Package recipe repository url here, for issues about the package>"
   description = "A Command line tool for arbitrary environments"
   settings = "os", "compiler", "build_type", "arch"
   options = {"shared": [True, False], "with_tests": [True, False], "with_demo": [True, False]}
   default_options = {"shared": False, "with_tests": False, "with_demo": False}
   generators = "cmake"

   def requirements(self):
      self.requires("sfml/2.5.1@bincrafters/stable")
      self.options["sfml"].shared = True
      self.options["sfml"].graphics = True
      self.options["sfml"].window = True
      self.requires("bzip2/1.0.8@conan/stable")

   def build_requirements(self):
      if self.options.with_tests == True :
         self.build_requires("gtest/1.10.0@nerdhaus-mirror/stable")
      self.build_requires("boost/1.71.0@conan/stable")

   def build(self):
      cmake = CMake(self)
      cmake.definitions["BUILD_WITH_TESTS"] = self.options.with_tests
      cmake.definitions["BUILD_WITH_DEMO"] = self.options.with_demo
      cmake.configure()
      cmake.build()

   def imports(self):
      if(self.settings.os=="Windows"):
         self.copy("*.dll", dst="../bin/"+str(self.settings.build_type), src="bin")
         self.copy("*.dylib*", dst="../bin/"+str(self.settings.build_type), src="lib")
      else:
         self.copy("*.dll", dst="../bin", src="bin")
         self.copy("*.dylib*", dst="../bin", src="lib")

   def package(self):
      cmake = CMake(self)
      cmake.configure()
      cmake.install()

   def deploy(self):
      self.copy("*")