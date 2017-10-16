# Ray Tracer

This program 
One Paragraph of project description goes here

## Getting Started

These instructions will get you a copy of the project up and running on your local machine for development and testing purposes. See deployment for notes on how to deploy the project on a live system.

### Prerequisites

All frameworks are included

Send me a notification if you find compatibility issues

### Installing

Run the Makefile with a make command (wait a few seconds)

```
make
```

Then run the binary file with a scene as argument

```
./rt scene/scene7.xml
```

Modify and play around with the scenes in the Scenes folder, you can even make your own !

## Clean

Clean your directory using the available commands

Delete object files

```
make clean
```

Delete binaries and libraries

```
make fclean
```

## Keyboard Shortcuts

The shortcut are essential to navigate and move objects

### Camera Controls

- <kbd>w</kbd> / <kbd>s</kbd> rotate camera up / down
- <kbd>a</kbd> / <kbd>d</kbd> rotate camera left / right
- &uarr / <kbd>&darr</kbd> move forward / backward
- <kbd>&larr</kbd> / <kbd>&rarr</kbd> move left / right
- <kbd>tab</kbd> reset to initial position

### Objects Controls

Select an object with `Left Click`. Unselect with `Right Click`

Object movement and rotation use the same controls as the camera

- <kbd>x</kbd> / <kbd>c</kbd> / <kbd>v</kbd> modify object color with r/g/b values
- <kbd>+</kbd> / <kbd>-</kbd> modify object size
- <kbd>f</kbd> change object texture (note that some textures are only available for specific object type e.g Sphere)
- <kbd>n</kbd> modify the intensity of normal variation for bump mapping
- <kbd>delete</kbd> delete object
- <kbd>z</kbd> print object informations on the terminal
- <kbd>i</kbd> add sphere (on current position)
- <kbd>u</kbd> add torus (on current position)
- <kbd>y</kbd> add plan (on current position)
- <kbd>t</kbd> add light (on current position)
- <kbd>r</kbd> add triangle (on current position)

### Options Controls

- <kbd>q</kbd> apply filter to the scene (sepia/negative/blue-saturated/grey/red/green/blue)
- <kbd>k</kbd> / <kbd>l</kbd> + / - antialiasing
- <kbd>o</kbd> take a screenshot saved in `img/` folder
- <kbd>m</kbd> activate motion blur
- <kbd>n</kbd> increase bump mapping intensity (only on objects with bump mapping activated)
- <kbd>1</kbd> / <kbd>2</kbd> / <kbd>3</kbd> / <kbd>4</kbd> / <kbd>5</kbd> switch scene

### Break down into end to end tests

Explain what these tests test and why

```
Give an example
```

### And coding style tests

Explain what these tests test and why

```
Give an example
```

## Deployment

Add additional notes about how to deploy this on a live system

## Built With

* [Dropwizard](http://www.dropwizard.io/1.0.2/docs/) - The web framework used
* [Maven](https://maven.apache.org/) - Dependency Management
* [ROME](https://rometools.github.io/rome/) - Used to generate RSS Feeds

## Contributing

Please read [CONTRIBUTING.md](https://gist.github.com/PurpleBooth/b24679402957c63ec426) for details on our code of conduct, and the process for submitting pull requests to us.

## Versioning

We use [SemVer](http://semver.org/) for versioning. For the versions available, see the [tags on this repository](https://github.com/your/project/tags). 

## Authors

* **Billie Thompson** - *Initial work* - [PurpleBooth](https://github.com/PurpleBooth)

See also the list of [contributors](https://github.com/your/project/contributors) who participated in this project.

## License

This project is licensed under the MIT License - see the [LICENSE.md](LICENSE.md) file for details

## Acknowledgments

* Hat tip to anyone who's code was used
* Inspiration
* etc

