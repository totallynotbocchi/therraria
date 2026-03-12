target("main")
do
  set_kind("binary")
  set_languages("c++23")

  add_files("src/*.cpp", "src/***.cpp")
  add_headerfiles("src/**.hpp")
  set_pcxxheader("src/pch.hpp")

  add_links("raylib")

  after_build(function(target)
    os.rm(path.join(target:targetdir(), "assets"))
    os.cp("assets/", path.join(target:targetdir(), "assets"))
  end)
end
